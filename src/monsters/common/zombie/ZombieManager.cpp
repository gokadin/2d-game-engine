#include <iostream>
#include "ZombieManager.h"
#include "Zombie.h"

ZombieManager::ZombieManager(MapState *mapState, MapBounds *bounds):
        MonsterManager(1000, mapState, bounds)
{
    if (!m_texture.loadFromFile("../src/storage/game/monsters/common/zombie/texture.png"))
    {
        std::cout << "Could not load texture." << std::endl;
    }

    Zombie *zombie = new Zombie(nextId(), &m_texture, mapState, bounds);
    zombie->setPosition(1100.0f, 650.0f);
    zombie->setHitBox(64, 112);
    addMonster(zombie);
}
