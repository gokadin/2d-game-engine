#include <iostream>
#include <map>
#include "InventorySideBar.h"
#include "../../data/IO/KeyValueReader.h"
#include "../../core/Engine.h"

InventorySideBar::InventorySideBar(EquipmentManager *equipmentManager):
        m_equipmentManager(equipmentManager), m_grabbedItem(NULL)
{
    if (!m_texture.loadFromFile("../src/storage/game/userInterface/inventory/texture.png"))
    {
        std::cout << "Could not load inventory texture." << std::endl;
    }

    m_sprite.setTexture(m_texture);

    std::map<std::string, std::string> metadata = KeyValueReader::read("../src/storage/game/userInterface/inventory/metadata");

    m_width = std::stoi(metadata["WIDTH"]);
    m_height = std::stoi(metadata["HEIGHT"]);
    m_x = Engine::SCREEN_WIDTH - m_width;
    m_y = 0;
    m_sprite.setPosition(m_x, m_y);
    m_slotsMargin = std::stoi(metadata["SLOTS_MARGIN"]);
    m_slotSize = std::stoi(metadata["SLOT_SIZE"]);
    m_inventorySlotsBeginPosition.x = std::stoi(metadata["SLOTS_BEGIN_X"]);
    m_inventorySlotsBeginPosition.y = std::stoi(metadata["SLOTS_BEGIN_Y"]);
    int numSlotsPerRow = std::stoi(metadata["NUM_SLOTS_PER_ROW"]);
    int numSlotsPerColumn = std::stoi(metadata["NUM_SLOTS_PER_COLUMN"]);

    for (int i = 0; i < numSlotsPerColumn; i++)
    {
        std::vector<InventorySlot> slotRow;
        for (int j = 0; j < numSlotsPerRow; j++)
        {
            InventorySlot slot;
            slot.x = m_x + m_inventorySlotsBeginPosition.x + (m_slotsMargin + j * (m_slotSize + m_slotsMargin));
            slot.y = m_inventorySlotsBeginPosition.y + (m_slotsMargin + i * (m_slotSize + m_slotsMargin));
            slot.width = m_slotSize;
            slot.height = m_slotSize;
            slot.row = j;
            slot.column = i;
            slot.item = NULL;
            slot.isLastRow = i == numSlotsPerColumn - 1;
            slot.isFirstRow = i == 0;
            slot.isItemMainSlot = false;
            slotRow.push_back(slot);
        }
        m_slots.push_back(slotRow);
    }

    m_equipmentSlots[equipment_type::MAIN_HAND].x = m_x + std::stoi(metadata["MAIN_HAND_SLOT_X"]);
    m_equipmentSlots[equipment_type::MAIN_HAND].y = std::stoi(metadata["MAIN_HAND_SLOT_Y"]);
    m_equipmentSlots[equipment_type::MAIN_HAND].width = std::stoi(metadata["MAIN_HAND_SLOT_WIDTH"]);
    m_equipmentSlots[equipment_type::MAIN_HAND].height = std::stoi(metadata["MAIN_HAND_SLOT_HEIGHT"]);
    m_equipmentSlots[equipment_type::MAIN_HAND].item = NULL;

    m_slotHighlight.setOutlineThickness(1);
    m_slotHighlight.setOutlineColor(sf::Color(240, 240, 240, 150));
    m_slotHighlight.setFillColor(sf::Color::Transparent);

    tempS = new ThousandTruths();
    m_slots[2][2].item = tempS;
    m_slots[2][2].isItemMainSlot = true;
    m_slots[3][2].item = tempS;
}

InventorySideBar::~InventorySideBar()
{
    delete tempS;
}

void InventorySideBar::processEvent(sf::Event &event)
{
    switch (event.type)
    {
        case sf::Event::MouseButtonPressed:
            processMouseButtonPressed(event);
            break;
        case sf::Event::MouseButtonReleased:
            processMouseButtonReleased(event);
            break;
    }
}

void InventorySideBar::processMouseButtonPressed(sf::Event &event)
{
    if (event.mouseButton.x < m_inventorySlotsBeginPosition.x || event.mouseButton.y < m_inventorySlotsBeginPosition.y)
    {
        InventorySlot *slot = mouseOverEquipmentSlot(event.mouseButton.x, event.mouseButton.y);
        if (slot == NULL || slot->item == NULL)
        {
            return;
        }

        m_grabbedItem = slot->item;
        slot->item = NULL;
        m_equipmentManager->unequipMainHand();

        return;
    }

    InventorySlot *slot = mouseOverInventorySlot(event.mouseButton.x, event.mouseButton.y);
    if (slot == NULL || slot->item == NULL)
    {
        return;
    }

    m_grabbedItem = slot->item;

    if (slot->item->slotSize() == 2)
    {
        int extensionSlotColumn = slot->isItemMainSlot ? slot->column + 1 : slot->column - 1;
        m_slots[extensionSlotColumn][slot->row].item = NULL;
        m_slots[extensionSlotColumn][slot->row].isItemMainSlot = false;
    }

    slot->item = NULL;
    slot->isItemMainSlot = false;
}

void InventorySideBar::processMouseButtonReleased(sf::Event &event)
{
    if (m_grabbedItem == NULL)
    {
        return;
    }

    if (event.mouseButton.x >= m_inventorySlotsBeginPosition.x && event.mouseButton.y >= m_inventorySlotsBeginPosition.y)
    {
        InventorySlot *slot = mouseOverInventorySlot(event.mouseButton.x, event.mouseButton.y);
        if (slot == NULL || (m_grabbedItem->slotSize() == 2 && slot->isLastRow))
        {
            return;
        }

        slot->item = m_grabbedItem;
        slot->isItemMainSlot = true;
        if (m_grabbedItem->slotSize() == 2)
        {
            m_slots[slot->column + 1][slot->row].item = m_grabbedItem;
        }
        m_grabbedItem = NULL;

        return;
    }

    if (!m_grabbedItem->isEquipable())
    {
        return;
    }

    InventorySlot *slot = mouseOverEquipmentSlot(event.mouseButton.x, event.mouseButton.y);
    if (slot == NULL)
    {
        return;
    }

    slot->item = m_grabbedItem;
    m_grabbedItem = NULL;
    m_equipmentManager->equipMainHand((Weapon*)slot->item);
}

void InventorySideBar::update()
{

}

void InventorySideBar::draw(sf::RenderWindow *window)
{
    if (!m_isOpen)
    {
        return;
    }

    window->draw(m_sprite);

    drawSlotBackgrounds(window);

    drawSlotHighlights(window);

    drawSlotItems(window);
}

void InventorySideBar::drawSlotItems(sf::RenderWindow *window)
{
    for (int i = 0; i < m_slots.size(); i++)
    {
        for (int j = 0; j < m_slots[i].size(); j++)
        {
            if (!m_slots[i][j].isItemMainSlot || m_slots[i][j].item == NULL)
            {
                continue;
            }

            m_slots[i][j].item->icon().setPosition(m_slots[i][j].x, m_slots[i][j].y);
            window->draw(m_slots[i][j].item->icon());
        }
    }

    for (std::pair<equipment_type, InventorySlot> pair : m_equipmentSlots)
    {
        if (pair.second.item == NULL)
        {
            continue;
        }

        EquipableItem *equipableItem = (EquipableItem*)pair.second.item;
        equipableItem->icon().setPosition(pair.second.x, pair.second.y);
        window->draw(equipableItem->icon());
    }

    // maybe should move this out, along with many other things in this class
    if (m_grabbedItem != NULL)
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(*((sf::Window*)window));
        m_grabbedItem->icon().setPosition(mousePosition.x - 25, mousePosition.y - 51); // temp values
        window->draw(m_grabbedItem->icon());
    }
}

void InventorySideBar::drawSlotBackgrounds(sf::RenderWindow *window)
{
    for (int i = 0; i < m_slots.size(); i++)
    {
        for (int j = 0; j < m_slots[i].size(); j++)
        {
            if (!m_slots[i][j].isItemMainSlot || m_slots[i][j].item == NULL)
            {
                continue;
            }

            configureSlotBackground(m_slots[i][j]);
            window->draw(m_slotBackground);
        }
    }

    for (std::pair<equipment_type, InventorySlot> pair : m_equipmentSlots)
    {
        if (pair.second.item == NULL)
        {
            continue;
        }

        configureSlotBackground(pair.second);
        window->draw(m_slotBackground);
    }
}

void InventorySideBar::drawSlotHighlights(sf::RenderWindow *window)
{
    if (m_grabbedItem == NULL)
    {
        return;
    }

    sf::Vector2i mousePosition = sf::Mouse::getPosition(*((sf::Window*)window));
    if (mousePosition.x >= m_inventorySlotsBeginPosition.x && mousePosition.y >= m_inventorySlotsBeginPosition.y)
    {
        InventorySlot *slot = mouseOverInventorySlot(mousePosition.x, mousePosition.y);
        if (slot == NULL || (m_grabbedItem->slotSize() == 2 && slot->isLastRow))
        {
            return;
        }

        m_slotHighlight.setPosition(slot->x, slot->y);
        m_slotHighlight.setSize(sf::Vector2f(m_slotSize, m_grabbedItem->slotSize() == 1 ? m_slotSize : m_slotSize * 2 + 1));
        window->draw(m_slotHighlight);

        return;
    }
}

void InventorySideBar::configureSlotBackground(InventorySlot &slot)
{
    m_slotBackground.setPosition(slot.x, slot.y);
    m_slotBackground.setFillColor(sf::Color(50, 25, 255, 75));
    m_slotBackground.setSize(sf::Vector2f(m_slotSize, slot.item->slotSize() == 1 ? m_slotSize : m_slotSize * 2 + 1));
}

bool InventorySideBar::isMouseOnUI(int x, int y)
{
    return m_isOpen && x >= m_x;
}

InventorySlot* InventorySideBar::mouseOverInventorySlot(int mouseX, int mouseY)
{
    for (int i = 0; i < m_slots.size(); i++)
    {
        for (int j = 0; j < m_slots[i].size(); j++)
        {
            if (mouseX >= m_slots[i][j].x &&
                mouseX <= m_slots[i][j].x + m_slotSize &&
                mouseY >= m_slots[i][j].y &&
                mouseY <= m_slots[i][j].y + m_slotSize)
            {
                return &m_slots[i][j];
            }
        }
    }

    return NULL;
}

InventorySlot *InventorySideBar::mouseOverEquipmentSlot(int mouseX, int mouseY)
{
    for (std::pair<equipment_type, InventorySlot> pair : m_equipmentSlots)
    {
        if (mouseX >= pair.second.x && mouseX <= pair.second.x + pair.second.width &&
                mouseY >= pair.second.y && mouseY <= pair.second.y + pair.second.height)
        {
            return &m_equipmentSlots[pair.first];
        }
    }

    return NULL;
}
