#include "Dialogue.h"
#include "../InteractionManager.h"
#include "../../../../core/Engine.h"
#include "../../../../events/npcEvents/InteractionCancelledEvent.h"
#include "../../../../events/quests/QuestAcceptedEvent.h"

Dialogue::Dialogue(std::string title, GameFonts *fonts, quest_name questName)
        : Interaction(interaction_type::DIALOGUE, title, fonts),
          m_mainBox(sf::Vector2f(600, 400)),
          m_buttonCancel(BUTTON_WIDTH, BUTTON_HEIGHT),
          m_buttonAccept(BUTTON_WIDTH, BUTTON_HEIGHT),
          m_questName(questName)
{
    m_mainBox.setOutlineThickness(3);
    m_mainBox.setOutlineColor(BORDER_COLOR);
    m_mainBox.setFillColor(BACKGROUND_COLOR);
    m_mainBox.setPosition((Engine::SCREEN_WIDTH - 600) / 2, 100);

    m_buttonCancel.setOutlineThickness(1);
    m_buttonCancel.setOutlineColor(BUTTON_BORDER_COLOR);
    m_buttonCancel.setFillColor(BUTTON_BACKGROUND_COLOR);
    m_buttonCancel.setPosition(m_mainBox.getPosition().x + MARGIN_X,
                               m_mainBox.getPosition().y + m_mainBox.getSize().y - BUTTON_HEIGHT - MARGIN_Y);
    m_buttonCancel.setText(new sf::Text("Close", m_fonts->getDefault()));

    if (m_questName != quest_name::NONE)
    {
        m_buttonAccept.setOutlineThickness(1);
        m_buttonAccept.setOutlineColor(BUTTON_BORDER_COLOR);
        m_buttonAccept.setFillColor(BUTTON_BACKGROUND_COLOR);
        m_buttonAccept.setPosition(m_mainBox.getPosition().x + m_mainBox.getSize().x - MARGIN_X - BUTTON_WIDTH,
                                   m_mainBox.getPosition().y + m_mainBox.getSize().y - BUTTON_HEIGHT - MARGIN_Y);
        m_buttonAccept.setText(new sf::Text("Accept", m_fonts->getDefault()));
    }
}

Dialogue::Dialogue(std::string title, GameFonts *fonts)
        : Dialogue(title, fonts, quest_name::NONE)
{}

void Dialogue::processEvent(sf::Event &event)
{
    switch (event.type)
    {
        case sf::Event::MouseButtonPressed:
            handleMouseButtonPressed(event.mouseButton.x, event.mouseButton.y);
            break;
    }
}

void Dialogue::draw(sf::RenderWindow *window)
{
    window->draw(m_mainBox);
    m_buttonCancel.draw(window);

    if (m_questName != quest_name::NONE)
    {
        m_buttonAccept.draw(window);
    }
}

void Dialogue::update()
{

}

bool Dialogue::isMouseOnInteraction(int x, int y)
{
    return x >= m_mainBox.getPosition().x && x <= m_mainBox.getPosition().x + m_mainBox.getSize().x &&
           y >= m_mainBox.getPosition().y && y <= m_mainBox.getPosition().y + m_mainBox.getSize().y;
}

void Dialogue::activate()
{

}

void Dialogue::handleMouseButtonPressed(int mouseX, int mouseY)
{
    if (m_buttonCancel.isMouseOnButton(mouseX, mouseY))
    {
        notifyObservers(std::make_shared<InteractionCancelledEvent>(event_type::INTERACTION_CANCELLED));
    }

    if (m_questName != quest_name::NONE && m_buttonAccept.isMouseOnButton(mouseX, mouseY))
    {
        notifyObservers(std::make_shared<QuestAcceptedEvent>(event_type::QUEST_ACCEPTED, m_questName));
    }
}
