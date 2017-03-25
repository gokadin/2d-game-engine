#include <iostream>
#include <map>
#include "InventorySideBar.h"
#include "../../data/IO/KeyValueReader.h"
#include "../../core/Engine.h"

InventorySideBar::InventorySideBar():
        m_grabbedItem(NULL)
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
    m_slotsBeginX = std::stoi(metadata["SLOTS_BEGIN_X"]);
    m_slotsBeginY = std::stoi(metadata["SLOTS_BEGIN_Y"]);
    m_slotsMargin = std::stoi(metadata["SLOTS_MARGIN"]);
    m_slotSize = std::stoi(metadata["SLOT_SIZE"]);

    for (int i = 0; i < NUM_SLOTS_IN_COLUMN; i++)
    {
        std::vector<Item *> slotRow;
        std::vector<int> positionRowX;
        std::vector<int> positionRowY;
        for (int j = 0; j < NUM_SLOTS_IN_ROW; j++)
        {
            slotRow.push_back(NULL);
            positionRowX.push_back(m_x + m_slotsBeginX + (m_slotsMargin + i * (m_slotSize + m_slotsMargin)));
            positionRowY.push_back(m_slotsBeginY + (m_slotsMargin + j * (m_slotSize + m_slotsMargin)));
        }
        m_slots.push_back(slotRow);
        m_slotPositionsX.push_back(positionRowX);
        m_slotPositionsY.push_back(positionRowY);
    }

    m_mainHandSlotX = std::stoi(metadata["MAIN_HAND_SLOT_X"]);
    m_mainHandSlotY = std::stoi(metadata["MAIN_HAND_SLOT_Y"]);
    m_mainHandSlotWidth = std::stoi(metadata["MAIN_HAND_SLOT_WIDTH"]);
    m_mainHandSlotHeight = std::stoi(metadata["MAIN_HAND_SLOT_HEIGHT"]);

    tempS = new ThousandTruths();
    m_slots[2][2] = tempS;
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
            for (int i = 0; i < NUM_SLOTS_IN_COLUMN; i++)
            {
                for (int j = 0; j < NUM_SLOTS_IN_ROW; j++)
                {
                    if (event.mouseButton.x >= m_slotPositionsX[i][j] &&
                        event.mouseButton.x <= m_slotPositionsX[i][j] + m_slotSize &&
                        event.mouseButton.y >= m_slotPositionsY[i][j] &&
                        event.mouseButton.y <= m_slotPositionsY[i][j] + m_slotSize)
                    {
                        m_grabbedItem = m_slots[i][j];
                        m_slots[i][j] = NULL;

                        break;
                    }
                }
            }
            break;
        case sf::Event::MouseButtonReleased:
            if (m_grabbedItem == NULL)
            {
                break;
            }

            for (int i = 0; i < NUM_SLOTS_IN_COLUMN; i++)
            {
                for (int j = 0; j < NUM_SLOTS_IN_ROW; j++)
                {
                    if (event.mouseButton.x >= m_slotPositionsX[i][j] &&
                        event.mouseButton.x <= m_slotPositionsX[i][j] + m_slotSize &&
                        event.mouseButton.y >= m_slotPositionsY[i][j] &&
                        event.mouseButton.y <= m_slotPositionsY[i][j] + m_slotSize)
                    {
                        m_slots[i][j] = m_grabbedItem;
                        m_grabbedItem = NULL;

                        break;
                    }
                }
            }

            // ...
            break;
    }
}

void InventorySideBar::update()
{

}

void InventorySideBar::draw(sf::RenderWindow *window)
{
    if (m_isOpen)
    {
        window->draw(m_sprite);

        drawSlotItems(window);
    }
}

void InventorySideBar::drawSlotItems(sf::RenderWindow *window)
{
    for (int i = 0; i < m_slots.size(); i++)
    {
        for (int j = 0; j < m_slots[i].size(); j++)
        {
            if (m_slots[i][j] == NULL)
            {
                continue;
            }

            m_slots[i][j]->icon().setPosition(m_slotPositionsX[i][j], m_slotPositionsY[i][j]);
            window->draw(m_slots[i][j]->icon());
        }
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
