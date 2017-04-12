#include "Objective.h"
#include "../../events/quests/ObjectiveCompletedEvent.h"

Objective::Objective(std::string description, int totalCount)
        : m_description(description),
          m_totalCount(totalCount),
          m_isCompleted(false),
          m_currentCount(0)
{}

void Objective::notify(std::shared_ptr<Event> event)
{
    if (m_isCompleted)
    {
        return;
    }
}

void Objective::complete()
{
    m_isCompleted = true;
    notify(std::make_shared<ObjectiveCompletedEvent>());
}
