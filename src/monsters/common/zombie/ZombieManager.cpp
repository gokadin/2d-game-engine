#include <iostream>
#include "ZombieManager.h"
#include "Zombie.h"

ZombieManager::ZombieManager(int baseId, MapState *mapState, MapBounds *bounds, CharacterGraphics *characterGraphics):
        MonsterManager(baseId, mapState, bounds, characterGraphics)
{
    if (!m_texture.loadFromFile("../src/storage/game/monsters/common/zombie/texture.png"))
    {
        std::cout << "Could not load texture." << std::endl;
    }

    Zombie *zombie = new Zombie(nextId(), &m_texture, mapState, bounds);
    zombie->setPosition(100.0f, 100.0f);
    zombie->setHitBox(64, 112);
    zombie->setIdleMoveSpeed(1.5);
    zombie->setAggroMoveSpeed(2.5);
    zombie->setAggroRange(100);
    zombie->setMaxLife(100);
    zombie->setCurrentLife(100);
    addMonster(zombie);

//    Zombie *zombie2 = new Zombie(nextId(), &m_texture, mapState, bounds);
//    zombie2->setPosition(2100.0f, 650.0f);
//    zombie2->setHitBox(64, 112);
//    zombie2->setIdleMoveSpeed(1.5);
//    zombie2->setAggroMoveSpeed(2.5);
//    zombie2->setAggroRange(100);
//    zombie2->setMaxLife(100);
//    zombie2->setCurrentLife(100);
//    addMonster(zombie2);
//
//    Zombie *zombie3 = new Zombie(nextId(), &m_texture, mapState, bounds);
//    zombie3->setPosition(1800.0f, 550.0f);
//    zombie3->setHitBox(64, 112);
//    zombie3->setIdleMoveSpeed(1.5);
//    zombie3->setAggroMoveSpeed(2.5);
//    zombie3->setAggroRange(100);
//    zombie3->setMaxLife(100);
//    zombie3->setCurrentLife(100);
//    addMonster(zombie3);

    m_updater = new ZombieUpdater(m_bounds, m_mapState, m_characterGraphics, m_monsters);
}

ZombieManager::~ZombieManager()
{
    delete m_updater;
}

void ZombieManager::update()
{
    MonsterManager::update();

    m_updater->update();
}
