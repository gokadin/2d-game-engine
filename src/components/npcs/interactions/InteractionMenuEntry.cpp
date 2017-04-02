#include "InteractionMenuEntry.h"

InteractionMenuEntry::InteractionMenuEntry(Interaction *interaction, GameFonts *fonts):
        m_interaction(interaction)
{
    m_text.setFont(fonts->getDefault());
    m_text.setCharacterSize(14);
    m_text.setColor(sf::Color::White);
    m_text.setString(m_interaction->title());
}

InteractionMenuEntry::~InteractionMenuEntry()
{
    delete m_interaction;
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
    m_text.setPosition(x, y);
}

float InteractionMenuEntry::entryWidth()
{
    return m_text.getLocalBounds().width;
}
