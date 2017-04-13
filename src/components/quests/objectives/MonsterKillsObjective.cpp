#include "MonsterKillsObjective.h"
#include "../../../events/monsters/MonsterDiedEvent.h"
#include "../../../events/quests/ObjectiveUpdatedEvent.h"

MonsterKillsObjective::MonsterKillsObjective(std::string description, int totalCount, monster_type monsterType)
        : Objective(description, totalCount),
          m_monsterType(monsterType)
{}

void MonsterKillsObjective::notify(std::shared_ptr<Event> event)
{
    if (m_isCompleted)
    {
        return;
    }

    switch (event->type())
    {
        case event_type::MONSTER_DIED:
            handleMonsterDied((std::static_pointer_cast<MonsterDiedEvent>(event))->monster());
            break;
    }
}

void MonsterKillsObjective::handleMonsterDied(Monster *monster)
{
    if (monster->type() != m_monsterType)
    {
        return;
    }

    m_currentCount++;
    notifyObservers(std::make_shared<ObjectiveUpdatedEvent>());
    if (m_currentCount == m_totalCount)
    {
        complete();
    }
}
