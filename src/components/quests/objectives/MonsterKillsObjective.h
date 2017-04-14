#ifndef SFMLDEMO_MONSTERKILLSOBJECTIVE_H
#define SFMLDEMO_MONSTERKILLSOBJECTIVE_H

#include "../Objective.h"
#include "../../../monsters/Monster.h"

class MonsterKillsObjective : public Objective
{
public:
    MonsterKillsObjective(std::string description, int totalCount, monster_type monsterType);

    void handleEvent(std::shared_ptr<Event> event);

private:
    monster_type m_monsterType;

    void handleMonsterDied(Monster *monster);
};

#endif //SFMLDEMO_MONSTERKILLSOBJECTIVE_H
