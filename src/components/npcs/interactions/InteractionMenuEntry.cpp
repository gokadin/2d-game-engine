#include <SFML/Window/Event.hpp>
#include "InteractionMenuEntry.h"

InteractionMenuEntry::InteractionMenuEntry(Interaction *interaction, GameFonts *fonts):
        m_interaction(interaction)
{
    m_text.setFont(fonts->getDefault());
    m_text.setCharacterSize(16);
    m_text.setColor(sf::Color::White);
    m_text.setString(m_interaction->title());
}

InteractionMenuEntry::~InteractionMenuEntry()
{
    delete m_interaction;
}

bool InteractionMenuEntry::processEvent(sf::Event &event)
{
    switch (event.type)
    {
        case sf::Event::MouseButtonPressed:
            if (isMouseOnEntry(event))
            {
                handleMouseClick(event);
                return true;
            }
            break;
    }

    return false;
}

bool InteractionMenuEntry::isMouseOnEntry(sf::Event &event)
{
    return event.mouseButton.x >= m_x && event.mouseButton.x <= m_x + m_width &&
           event.mouseButton.y >= m_y && event.mouseButton.y <= m_y + HEIGHT;
}

void InteractionMenuEntry::handleMouseClick(sf::Event &event)
{
    // ...
    // maybe use interaction() getter and handle this logic in the interaction manager
}

void InteractionMenuEntry::draw(sf::RenderWindow *window)
{
    window->draw(m_text);
}

Interaction *InteractionMenuEntry::interaction()
{
    return m_interaction;
}

void InteractionMenuEntry::setPosition(float x, float y)
{
    m_x = x;
    m_y = y;
    m_text.setPosition(x + (m_width - m_text.getLocalBounds().width) / 2, y + PADDING_Y);
}
