#include "MonsterManagerUpdater.h"

MonsterManagerUpdater::MonsterManagerUpdater(MapBounds *mapBounds, CharacterGraphics *characterGraphics,
                                             std::map<int, Monster *> monsters):
        m_mapBounds(mapBounds), m_characterGraphics(characterGraphics), m_monsters(monsters)
{}

void MonsterManagerUpdater::aggro()
{
    for (auto pair : m_monsters)
    {
        if (pair.second->isAlive())
        {
            m_aggroUpdater.update(pair.second);
        }
    }
}
