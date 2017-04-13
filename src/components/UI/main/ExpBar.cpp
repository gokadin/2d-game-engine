#include "ExpBar.h"

ExpBar::ExpBar(int skillBarX, int skillBarY, int skillBarWidth)
        : UIElement(skillBarX, skillBarY - HEIGHT, skillBarWidth, HEIGHT)
{
    m_expBar.setSize(sf::Vector2f(m_width, HEIGHT));
    m_expBar.setFillColor(sf::Color(0, 0, 0, 100));
    m_expBar.setOutlineThickness(1);
    m_expBar.setOutlineColor(sf::Color::Black);
    m_expBar.setPosition(m_x, m_y);

    m_expBarProgress.setSize(sf::Vector2f(0, HEIGHT));
    m_expBarProgress.setFillColor(sf::Color::Blue);
    m_expBarProgress.setOutlineThickness(1);
    m_expBarProgress.setOutlineColor(sf::Color::Black);
    m_expBar.setPosition(m_x, m_y);
}

void ExpBar::processEvent(sf::Event &event)
{

}

void ExpBar::update()
{

}

void ExpBar::draw(sf::RenderWindow *window)
{
    window->draw(m_expBar);
    window->draw(m_expBarProgress);
}
