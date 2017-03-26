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
            slot.x = m_x + m_inventorySlotsBeginPosition.x + (m_slotsMargin + i * (m_slotSize + m_slotsMargin));
            slot.y = m_inventorySlotsBeginPosition.y + (m_slotsMargin + j * (m_slotSize + m_slotsMargin));
            slotRow.push_back(slot);
        }
        m_slots.push_back(slotRow);
    }

    m_equipmentSlots[equipment_type::MAIN_HAND].x = m_x + std::stoi(metadata["MAIN_HAND_SLOT_X"]);
    m_equipmentSlots[equipment_type::MAIN_HAND].y = std::stoi(metadata["MAIN_HAND_SLOT_Y"]);
    m_equipmentSlots[equipment_type::MAIN_HAND].width = std::stoi(metadata["MAIN_HAND_SLOT_WIDTH"]);
    m_equipmentSlots[equipment_type::MAIN_HAND].height = std::stoi(metadata["MAIN_HAND_SLOT_HEIGHT"]);
    m_equipmentSlots[equipment_type::MAIN_HAND].item = NULL;

    tempS = new ThousandTruths();
    m_slots[2][2].item = tempS;
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
        EquipmentSlot *slot = mouseOverEquipmentSlot(event.mouseButton.x, event.mouseButton.y);
        if (slot == NULL || slot->item == NULL)
        {
            return;
        }

        m_grabbedItem = slot->item;
        m_equipmentManager->unequipMainHand((Weapon*)m_grabbedItem);
        slot->item = NULL;

        return;
    }

    InventorySlot *slot = mouseOverInventorySlot(event.mouseButton.x, event.mouseButton.y);
    if (slot == NULL || slot->item == NULL)
    {
        return;
    }

    m_grabbedItem = slot->item;
    slot->item = NULL;
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
        if (slot == NULL)
        {
            return;
        }

        slot->item = m_grabbedItem;
        m_grabbedItem = NULL;

        return;
    }

    if (!m_grabbedItem->isEquipable())
    {
        return;
    }

    EquipmentSlot *slot = mouseOverEquipmentSlot(event.mouseButton.x, event.mouseButton.y);
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

    drawSlotItems(window);
}

void InventorySideBar::drawSlotItems(sf::RenderWindow *window)
{
    for (int i = 0; i < m_slots.size(); i++)
    {
        for (int j = 0; j < m_slots[i].size(); j++)
        {
            if (m_slots[i][j].item == NULL)
            {
                continue;
            }

            m_slots[i][j].item->icon().setPosition(m_slots[i][j].x, m_slots[i][j].y);
            window->draw(m_slots[i][j].item->icon());
        }
    }

    for (std::pair<equipment_type, EquipmentSlot> pair : m_equipmentSlots)
    {
        if (pair.second.item == NULL)
        {
            continue;
        }

        EquipableItem *equipableItem = (EquipableItem*)pair.second.item;
        equipableItem->equippedIcon().setPosition(pair.second.x, pair.second.y);
        window->draw(equipableItem->equippedIcon());
    }

    // maybe should move this out, along with many other things in this class
    if (m_grabbedItem != NULL)
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(*((sf::Window*)window));
        m_grabbedItem->icon().setPosition(mousePosition.x - 25, mousePosition.y - 51); // temp values
        window->draw(m_grabbedItem->icon());
    }
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

EquipmentSlot *InventorySideBar::mouseOverEquipmentSlot(int mouseX, int mouseY)
{
    for (std::pair<equipment_type, EquipmentSlot> pair : m_equipmentSlots)
    {
        if (mouseX >= pair.second.x && mouseX <= pair.second.x + pair.second.width &&
                mouseY >= pair.second.y && mouseY <= pair.second.y + pair.second.height)
        {
            return &m_equipmentSlots[pair.first];
        }
    }

    return NULL;
}
