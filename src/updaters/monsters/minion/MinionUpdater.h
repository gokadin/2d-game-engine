#ifndef SFMLDEMO_MINIONUPDATER_H
#define SFMLDEMO_MINIONUPDATER_H

#include "../MonsterManagerUpdater.h"

class MinionUpdater : public MonsterManagerUpdater
{
public:
    MinionUpdater(MapBounds *mapBounds, MapState *mapState, CharacterGraphics *characterGraphics,
                  const std::map<int, Monster *> &monsters);

    void update();
};

#endif //SFMLDEMO_MINIONUPDATER_H
