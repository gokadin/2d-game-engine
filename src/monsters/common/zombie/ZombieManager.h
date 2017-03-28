#ifndef SFMLDEMO_ZOMBIEMANAGER_H
#define SFMLDEMO_ZOMBIEMANAGER_H

#include "../../MonsterManager.h"
#include "../../../updaters/monsters/zombie/ZombieUpdater.h"

class ZombieManager : public MonsterManager
{
public:
    ZombieManager(int baseId, MapState *mapState, MapBounds *bounds, CharacterGraphics *characterGraphics);
    ~ZombieManager();

    void update();

private:
    ZombieUpdater *m_updater;
};

#endif //SFMLDEMO_ZOMBIEMANAGER_H
