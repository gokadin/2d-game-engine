#include "AggroUpdater.h"

void AggroUpdater::update(Monster *monster)
{
    float distance = std::hypotf(monster->x() - Engine::CX, monster->y() - Engine::CY);
    if (distance > monster->aggroRange() || distance == 0)
    {
        return;
    }

    float diffX = monster->x() - Engine::CX;
    float diffY = monster->y() - Engine::CY;
    float angle = atan2(diffY, diffX);

    monster->move(monster->aggroMoveSpeed() * cos(angle), monster->aggroMoveSpeed() * sin(angle));
}
