#ifndef SFMLDEMO_SKILLSTATE_H
#define SFMLDEMO_SKILLSTATE_H

#include "../enums/SkillNames.h"
#include "ProjectileState.h"

struct SkillState
{
    skill_names name;
    bool isActive;
    std::vector<ProjectileState> projectiles;
    int castTimeMs;
};

#endif //SFMLDEMO_SKILLSTATE_H
