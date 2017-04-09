#include <SFML/Window/Event.hpp>
#include "InteractionMenuEntry.h"
#include "../../../events/npcEvents/InteractionMenuEntryClickedEvent.h"

InteractionMenuEntry::InteractionMenuEntry(int id, std::string title, GameFonts *fonts):
        m_id(id), m_title(title)
{
    m_text.setFont(fonts->getDefault());
    m_text.setCharacterSize(16);
    m_text.setColor(sf::Color::White);
    m_text.setString(title);
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
    notifyObservers(std::make_shared<InteractionMenuEntryClickedEvent>(event_type::INTERACTION_MENU_ENTRY_CLICKED, m_id));
}

void InteractionMenuEntry::draw(sf::RenderWindow *window)
{
    window->draw(m_text);
}

void InteractionMenuEntry::setPosition(float x, float y)
{
    m_x = x;
    m_y = y;
    m_text.setPosition(x + (m_width - m_text.getLocalBounds().width) / 2, y + PADDING_Y);
}
