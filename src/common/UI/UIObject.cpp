#include "UIObject.h"

UIObject::UIObject(int width, int height)
        : m_mainBox(sf::Vector2f(width, height))
{}

void UIObject::draw(sf::RenderWindow *window)
{
    window->draw(m_mainBox);
}

bool UIObject::isMouseOnButton(int x, int y)
{
    return x >= m_mainBox.getPosition().x &&
           x <= m_mainBox.getPosition().x + m_mainBox.getSize().x &&
           y >= m_mainBox.getPosition().y &&
           y <= m_mainBox.getPosition().y + m_mainBox.getSize().y;
}

void UIObject::setOutlineThickness(float thickness)
{
    m_mainBox.setOutlineThickness(thickness);
}

void UIObject::setOutlineColor(sf::Color color)
{
    m_mainBox.setOutlineColor(color);
}

void UIObject::setFillColor(sf::Color color)
{
    m_mainBox.setFillColor(color);
}

void UIObject::setPosition(int x, int y)
{
    m_mainBox.setPosition(x, y);
}

void UIObject::setPosition(float x, float y)
{
    m_mainBox.setPosition(x, y);
}
