#include "Intro.h"

Intro::Intro()
        : Quest(quest_name::INTRO_QUEST, "Introduction")
{
    addObjective(new Objective("Minions killed", 3));
}
