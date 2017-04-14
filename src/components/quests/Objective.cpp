#include "Objective.h"
#include "../../events/quests/ObjectiveCompletedEvent.h"

Objective::Objective(std::string description, int totalCount)
        : m_description(description),
          m_totalCount(totalCount),
          m_isCompleted(false),
          m_currentCount(0)
{}

void Objective::complete()
{
    m_isCompleted = true;
    handleEvent(std::make_shared<ObjectiveCompletedEvent>());
}
