#include <iostream>
#include "AggroUpdater.h"

AggroUpdater::AggroUpdater(MapState *mapState):
        m_mapState(mapState)
{}

void AggroUpdater::update(Monster *monster)
{
    float diffX = monster->x() - m_mapState->x() - Engine::CX;
    float diffY = monster->y() - m_mapState->y() - Engine::CY;

    if (monster->phase() != monster_phase::ATTACKING)
    {
        float distance = std::hypotf(diffX, diffY);
        if (distance > monster->aggroRange())
        {
            return;
        }

        monster->setPhase(monster_phase::ATTACKING);
    }

    double angle = atan2(diffY, diffX);
    monster->move(monster->aggroMoveSpeed() * -(float)cos(angle), monster->aggroMoveSpeed() * -(float)sin(angle));
}
