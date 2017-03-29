#include "MonsterManagerUpdater.h"

MonsterManagerUpdater::MonsterManagerUpdater(MapBounds *mapBounds, MapState *mapState, CharacterGraphics *characterGraphics,
                                             std::map<int, Monster *> monsters):
        m_mapBounds(mapBounds), m_mapState(mapState), m_characterGraphics(characterGraphics), m_monsters(monsters),
        m_aggroUpdater(mapState)
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
