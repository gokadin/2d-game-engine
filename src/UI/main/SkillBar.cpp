#include <iostream>
#include "SkillBar.h"
#include "../../data/IO/KeyValueReader.h"
#include "../../core/Engine.h"

SkillBar::SkillBar()
{
    if (!m_texture.loadFromFile("../src/storage/game/userInterface/main/skillBar/texture.png"))
    {
        std::cout << "Could not load skill bar texture." << std::endl;
    }

    m_sprite.setTexture(m_texture);

    std::map<std::string, std::string> metadata = KeyValueReader::read("../src/storage/game/userInterface/main/skillBar/metadata");

    m_width = std::stoi(metadata["WIDTH"]);
    m_height = std::stoi(metadata["HEIGHT"]);
    m_x = (Engine::SCREEN_WIDTH - m_width) / 2;
    m_y = Engine::SCREEN_HEIGHT - m_height;
    m_sprite.setPosition(m_x, 948); // what??????
}

void SkillBar::update()
{

}

void SkillBar::draw(sf::RenderWindow *window)
{
    window->draw(m_sprite);
}

bool SkillBar::isMouseOnUI(int x, int y)
{
    return false;
}
