#include "QuestTrackerUI.h"
#include "../../../events/quests/ActiveQuestChangedEvent.h"

QuestTrackerUI::QuestTrackerUI(GameFonts *fonts, QuestTracker &questTracker)
        : m_fonts(fonts),
          m_tracker(questTracker),
          m_mainTitle(MAIN_TITLE_STRING, m_fonts->getDefault())
{
    m_tracker.subscribe(this);

    m_mainTitle.setCharacterSize(14);
    m_mainTitle.setColor(MAIN_TITLE_COLOR);
    m_mainTitle.setPosition(START_X, START_Y);
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
}

bool QuestTrackerUI::isMouseOnUI(int x, int y)
{
    return false;
}

void QuestTrackerUI::notify(std::shared_ptr<Event> event)
{
    switch (event->type())
    {
        case event_type::ACTIVE_QUEST_CHANGED:
            handleActiveQuestChanged((std::static_pointer_cast<ActiveQuestChangedEvent>(event))->activeQuest());
            break;
    }
}

void QuestTrackerUI::handleActiveQuestChanged(Quest *activeQuest)
{
    m_mainTitle.setString("ACTIVE QUEST CHANGED");
}
