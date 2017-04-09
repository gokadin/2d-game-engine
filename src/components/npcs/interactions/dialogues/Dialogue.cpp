#include "Dialogue.h"
#include "../InteractionManager.h"
#include "../../../../core/Engine.h"

Dialogue::Dialogue(std::string title):
        Interaction(interaction_type::DIALOGUE, title), m_mainBox(sf::Vector2f(600, 400))
{
    m_mainBox.setOutlineThickness(3);
    m_mainBox.setOutlineColor(BORDER_COLOR);
    m_mainBox.setFillColor(BACKGROUND_COLOR);
    m_mainBox.setPosition((Engine::SCREEN_WIDTH - 600) / 2, 100);
}

void Dialogue::processEvent(sf::Event &event)
{

}

void Dialogue::draw(sf::RenderWindow *window)
{
    window->draw(m_mainBox);
}

void Dialogue::update()
{

}

bool Dialogue::isMouseOnInteraction(int x, int y)
{
    // ...

    return false;
}

void Dialogue::activate()
{
    std::cout << "activated dialogue" << std::endl;
}
