#include "MonsterManagerUpdater.h"

MonsterManagerUpdater::MonsterManagerUpdater(MapBounds *mapBounds, CharacterGraphics *characterGraphics,
                                             std::map<int, Monster *> monsters):
        m_mapBounds(mapBounds), m_characterGraphics(characterGraphics), m_monsters(monsters)
{}

void MonsterManagerUpdater::update()
{
    // put generic logic here
}
