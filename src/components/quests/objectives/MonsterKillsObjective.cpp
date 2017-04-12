#include "MonsterKillsObjective.h"
#include "../../../events/monsters/MonsterDiedEvent.h"

MonsterKillsObjective::MonsterKillsObjective(std::string description, int totalCount, monster_type monsterType)
        : Objective(description, totalCount),
          m_monsterType(monsterType)
{}

void MonsterKillsObjective::notify(std::shared_ptr<Event> event)
{
    Objective::notify(event);

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
    if (m_currentCount == m_totalCount)
    {
        complete();
    }
}
