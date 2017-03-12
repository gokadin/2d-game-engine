#ifndef SFMLDEMO_PROJECTILESTATE_H
#define SFMLDEMO_PROJECTILESTATE_H

#include "../enums/ProjectilePhases.h"

struct ProjectileState
{
    int targetX;
    int targetY;
    int currentX;
    int currentY;
    projectile_phases phase;
};

#endif //SFMLDEMO_PROJECTILESTATE_H
