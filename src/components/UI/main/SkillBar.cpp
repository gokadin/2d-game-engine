#include <iostream>
#include "SkillBar.h"
#include "../../../data/IO/KeyValueReader.h"
#include "../../../core/Engine.h"

SkillBar::SkillBar()
        : UIElement((Engine::SCREEN_WIDTH - 1400) / 2, Engine::SCREEN_HEIGHT - 80, 1400, 80),
          m_expBar(m_x, m_y, m_width)
{
    if (!m_texture.loadFromFile("../src/storage/game/userInterface/main/skillBar/texture.png"))
    {
        std::cout << "Could not load skill bar texture." << std::endl;
    }

    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_x, 948); // what??????
}

void SkillBar::processEvent(sf::Event &event)
{
    switch (event.type)
    {
        case sf::Event::MouseButtonPressed:

            break;
        case sf::Event::MouseButtonReleased:

            break;
    }
}

void SkillBar::update()
{

}

void SkillBar::draw(sf::RenderWindow *window)
{
    window->draw(m_sprite);
    m_expBar.draw(window);
}

void SkillBar::notify(std::shared_ptr<Event> event)
{
    switch (event->type())
    {

    }
}
