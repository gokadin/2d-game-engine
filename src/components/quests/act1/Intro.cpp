#include "Intro.h"
#include "../objectives/MonsterKillsObjective.h"

Intro::Intro()
        : Quest(quest_name::INTRO_QUEST, "Introduction")
{
    addObjective(new MonsterKillsObjective("Minions killed", 3, monster_type::MINION));
}
