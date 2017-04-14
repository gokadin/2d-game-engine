#include "QuestTracker.h"
#include "../../../events/quests/QuestAdded.h"

QuestTracker::QuestTracker()
        : m_quest(nullptr)
{}

QuestTracker::~QuestTracker()
{
    if (m_quest != nullptr)
    {
        delete m_quest;
    }
}

void QuestTracker::update()
{

}

void QuestTracker::acceptQuest(Quest *quest)
{
    if (m_quest != nullptr)
    {
        return;
    }

    m_quest = quest;
    notifyObservers(std::make_shared<QuestAddedEvent>(quest));
}

void QuestTracker::handleEvent(std::shared_ptr<Event> event)
{
    switch (event->type())
    {
        default:
            if (m_quest != nullptr)
            {
                m_quest->handleEvent(event);
            }
            break;
    }
}
