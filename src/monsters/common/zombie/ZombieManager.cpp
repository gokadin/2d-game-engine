#include <iostream>
#include "ZombieManager.h"
#include "Zombie.h"

ZombieManager::ZombieManager(MapState *mapState, std::vector<std::vector<int>> *bounds):
        MonsterManager(mapState, bounds)
{
    if (!m_texture.loadFromFile("../src/storage/game/monsters/common/zombie/texture.png"))
    {
        std::cout << "Could not load texture." << std::endl;
    }

    addMonster(new Zombie(&m_texture, mapState, 1100, 650));
}
