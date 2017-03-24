#include <iostream>
#include <map>
#include "InventorySideBar.h"
#include "../../data/IO/KeyValueReader.h"
#include "../../core/Engine.h"

InventorySideBar::InventorySideBar()
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
}

void InventorySideBar::update()
{

}

void InventorySideBar::draw(sf::RenderWindow *window)
{
    if (m_isOpen)
    {
        window->draw(m_sprite);
    }
}

bool InventorySideBar::isMouseOnUI(int x, int y)
{
    return m_isOpen && x >= m_x;
}
