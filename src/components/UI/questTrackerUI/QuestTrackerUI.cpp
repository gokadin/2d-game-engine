#include "QuestTrackerUI.h"
#include "../../../events/quests/QuestAdded.h"

QuestTrackerUI::QuestTrackerUI(GameFonts *fonts, QuestTracker *questTracker)
        : m_fonts(fonts),
          m_tracker(questTracker),
          m_mainTitle(MAIN_TITLE_STRING, m_fonts->getDefault()),
          m_questTitle("", m_fonts->getDefault()),
          m_objectiveCounterText("", m_fonts->getDefault()),
          m_objectiveDescriptionText("", m_fonts->getDefault())
{
    m_tracker->subscribe(this);

    m_mainTitle.setCharacterSize(14);
    m_mainTitle.setColor(MAIN_TITLE_COLOR);
    m_mainTitle.setPosition(START_X, START_Y);

    m_questTitle.setCharacterSize(12);
    m_questTitle.setColor(MAIN_TITLE_COLOR);
    m_questTitle.setPosition(START_X, START_Y + 50);

    m_objectiveCounterText.setCharacterSize(12);
    m_objectiveCounterText.setColor(MAIN_TITLE_COLOR);
    m_objectiveCounterText.setPosition(START_X, START_Y + 70);

    m_objectiveDescriptionText.setCharacterSize(12);
    m_objectiveDescriptionText.setColor(MAIN_TITLE_COLOR);
    m_objectiveDescriptionText.setPosition(START_X + 50, START_Y + 70);
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
    window->draw(m_objectiveCounterText);
    window->draw(m_objectiveDescriptionText);
}

bool QuestTrackerUI::isMouseOnUI(int x, int y)
{
    return false;
}

void QuestTrackerUI::notify(std::shared_ptr<Event> event)
{
    switch (event->type())
    {
        case event_type::QUEST_ADDED:
            handleQuestAdded((std::static_pointer_cast<QuestAddedEvent>(event))->quest());
            break;
        case event_type::OBJECTIVE_UPDATED:
            handleObjectiveUpdated();
            break;
    }
}

void QuestTrackerUI::handleQuestAdded(Quest *quest)
{
    m_questTitle.setString(quest->displayName());
    m_objectiveDescriptionText.setString(quest->objectives()[0]->description());
    updateObjectives();
    quest->objectives()[0]->subscribe(this); // don't do this!
}

void QuestTrackerUI::handleObjectiveUpdated()
{
    updateObjectives();
}

void QuestTrackerUI::updateObjectives()
{
    m_objectiveCounterText.setString(std::to_string(m_tracker->quest()->objectives()[0]->currentCount()) + "/" +
                                     std::to_string(m_tracker->quest()->objectives()[0]->totalCount()));
}
