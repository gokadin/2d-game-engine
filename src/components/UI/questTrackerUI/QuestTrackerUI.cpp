#include "QuestTrackerUI.h"
#include "../../../events/quests/QuestAdded.h"

QuestTrackerUI::QuestTrackerUI(GameFonts *fonts, QuestTracker *questTracker)
        : m_fonts(fonts),
          m_tracker(questTracker),
          m_mainTitle(MAIN_TITLE_STRING, m_fonts->getDefault()),
          m_questTitle("xxx", m_fonts->getDefault())
{
    m_tracker->subscribe(this);

    m_mainTitle.setCharacterSize(14);
    m_mainTitle.setColor(MAIN_TITLE_COLOR);
    m_mainTitle.setPosition(START_X, START_Y);

    m_questTitle.setCharacterSize(12);
    m_questTitle.setColor(MAIN_TITLE_COLOR);
    m_questTitle.setPosition(START_X, START_Y + 50);
}

void QuestTrackerUI::processEvent(sf::Event &event)
{

}

void QuestTrackerUI::update()
{

}

void QuestTrackerUI::draw(sf::RenderWindow *window)
{
    window->draw(m_mainTitle);
    window->draw(m_questTitle);
}

bool QuestTrackerUI::isMouseOnUI(int x, int y)
{
    return false;
}

void QuestTrackerUI::notify(std::shared_ptr<Event> event)
{
    switch (event->type())
    {
        case event_type::QUEST_ACCEPTED:
            handleQuestAdded((std::static_pointer_cast<QuestAddedEvent>(event))->quest());
            break;
    }
}

void QuestTrackerUI::handleQuestAdded(Quest *quest)
{
    // stopped here, name is empty...

    m_questTitle.setString(quest->displayName());
}
