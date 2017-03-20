#ifndef SFMLDEMO_ZOMBIEMANAGER_H
#define SFMLDEMO_ZOMBIEMANAGER_H

#include "../../MonsterManager.h"

class ZombieManager : public MonsterManager
{
public:
    ZombieManager(MapState *mapState, std::vector<std::vector<int>> *bounds);
};

#endif //SFMLDEMO_ZOMBIEMANAGER_H
