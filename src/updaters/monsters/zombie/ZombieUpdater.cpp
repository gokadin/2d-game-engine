#include "ZombieUpdater.h"

ZombieUpdater::ZombieUpdater(MapBounds *mapBounds, MapState *mapState, CharacterGraphics *characterGraphics, std::map<int, Monster *> monsters):
        MonsterManagerUpdater(mapBounds, mapState, characterGraphics, monsters), m_counter(0), m_mul(0.5f)
{}

void ZombieUpdater::update()
{
    for (std::pair<int, Monster *> pair : m_monsters)
    {
        if (!pair.second->isAlive())
        {
            continue;
        }

//        if ((pair.second->x() < Engine::CX + pair.second->aggroRange() || pair.second->x() > Engine::CX - pair.second->aggroRange()) &&
//            (pair.second->y() < Engine::CY + pair.second->aggroRange() || pair.second->y() > Engine::CY - pair.second->aggroRange()))
//        {
//            // ...
//        }
//        else
//        {
        pair.second->move(m_mul, m_mul);
//        }
    }

    m_counter++;
    if (m_counter < 240)
    {
        return;
    }

    m_counter = 0;
    m_mul = -m_mul;
}
