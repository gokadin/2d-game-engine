#include "QuestTracker.h"
#include "../../../events/quests/ActiveQuestChangedEvent.h"

QuestTracker::QuestTracker()
        : m_activeQuest(nullptr)
{}

QuestTracker::~QuestTracker()
{
    for (auto pair : m_quests)
    {
        delete pair.second;
    }
    m_quests.clear();
}

void QuestTracker::update()
{

}

void QuestTracker::acceptQuest(Quest *quest)
{
    m_quests[quest->name()] = quest;
    m_activeQuest = quest;
    notifyObservers(std::make_shared<ActiveQuestChangedEvent>(m_activeQuest));
}
