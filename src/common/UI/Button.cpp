#include "Button.h"

Button::Button(int width, int height)
        : UIObject(width, height),
          m_text(nullptr)
{}

Button::~Button()
{
    if (m_text != nullptr)
    {
        delete m_text;
    }
}

void Button::draw(sf::RenderWindow *window)
{
    UIObject::draw(window);

    if (m_text != nullptr)
    {
        window->draw(*m_text);
    }
}

void Button::setText(sf::Text *text)
{
    m_text = text;
    text->setPosition(m_mainBox.getPosition().x + (m_mainBox.getSize().x - m_text->getLocalBounds().width) / 2,
                     m_mainBox.getPosition().y + (m_mainBox.getSize().y - m_mainBox.getLocalBounds().height) / 2);
}
