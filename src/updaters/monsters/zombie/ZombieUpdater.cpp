#include "ZombieUpdater.h"

ZombieUpdater::ZombieUpdater(MapBounds *mapBounds, CharacterGraphics *characterGraphics, std::map<int, Monster *> monsters):
        MonsterManagerUpdater(mapBounds, characterGraphics, monsters), m_counter(0), m_mul(0.5f)
{}

void ZombieUpdater::update()
{
    std::cout << m_monsters.size() << std::endl;
    for (std::pair<int, Monster *> pair : m_monsters)
    {
        if ((pair.second->x() < Engine::CX + pair.second->aggroRange() || pair.second->x() > Engine::CX - pair.second->aggroRange()) &&
                (pair.second->y() < Engine::CY + pair.second->aggroRange() || pair.second->y() > Engine::CY - pair.second->aggroRange())) {
            double angle = atan2(Engine::CY, Engine::CX);
            float moveSpeedX = pair.second->aggroMoveSpeed() * (float)cos(angle);
            float moveSpeedY = pair.second->aggroMoveSpeed() * (float)sin(angle);

            pair.second->move(moveSpeedX, moveSpeedY);
        }
        else
        {
            pair.second->move(m_mul, m_mul);
        }
    }

    m_counter++;
    if (m_counter < 240)
    {
        return;
    }

    m_counter = 0;
    m_mul = -m_mul;
}
