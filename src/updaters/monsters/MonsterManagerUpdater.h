#ifndef SFMLDEMO_MONSTERMANAGERUPDATER_H
#define SFMLDEMO_MONSTERMANAGERUPDATER_H

#include "../Updater.h"
#include "../../data/definitions/character/CharacterGraphics.h"
#include "../../data/definitions/map/MapBounds.h"
#include "../../monsters/Monster.h"
#include "AggroUpdater.h"

class MonsterManagerUpdater : Updater
{
public:
    MonsterManagerUpdater(MapBounds *mapBounds, MapState *mapState, CharacterGraphics *characterGraphics,
                          std::map<int, Monster *> monsters);

protected:
    MapBounds *m_mapBounds;
    MapState *m_mapState;
    CharacterGraphics *m_characterGraphics;
    std::map<int, Monster *> m_monsters;

    virtual void aggro();

private:
    AggroUpdater m_aggroUpdater;
};

#endif //SFMLDEMO_MONSTERMANAGERUPDATER_H
