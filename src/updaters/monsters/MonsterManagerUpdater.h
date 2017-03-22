#ifndef SFMLDEMO_MONSTERMANAGERUPDATER_H
#define SFMLDEMO_MONSTERMANAGERUPDATER_H

#include "../Updater.h"
#include "../../data/definitions/character/CharacterGraphics.h"
#include "../../data/definitions/map/MapBounds.h"
#include "../../monsters/Monster.h"

class MonsterManagerUpdater : Updater
{
public:
    MonsterManagerUpdater(MapBounds *mapBounds, CharacterGraphics *characterGraphics,
                          std::map<int, Monster *> monsters);

protected:
    MapBounds *m_mapBounds;
    CharacterGraphics *m_characterGraphics;
    std::map<int, Monster *> m_monsters;
};

#endif //SFMLDEMO_MONSTERMANAGERUPDATER_H
