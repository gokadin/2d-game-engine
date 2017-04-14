#include "MinionManager.h"
#include "Minion.h"

MinionManager::MinionManager(int baseId, MapState *mapState, MapBounds *bounds, CharacterGraphics *characterGraphics):
        MonsterManager(baseId, mapState, bounds, characterGraphics)
{
    if (!m_texture.loadFromFile("../src/storage/game/monsters/common/minion/texture.png"))
    {
        std::cout << "Could not load texture." << std::endl;
    }

    Minion *minion = new Minion(nextId(), &m_texture, mapState, bounds);
    minion->setPosition(900.0f, 750.0f);
    minion->setHitBox(64, 128);
    minion->setIdleMoveSpeed(1.0f);
    minion->setAggroMoveSpeed(0.5f);
    minion->setAggroRange(300);
    minion->setMaxLife(100);
    minion->setCurrentLife(100);
    addMonster(minion);

    Minion *minion2 = new Minion(nextId(), &m_texture, mapState, bounds);
    minion2->setPosition(1300.0f, 750.0f);
    minion2->setHitBox(64, 128);
    minion2->setIdleMoveSpeed(1.0f);
    minion2->setAggroMoveSpeed(0.5f);
    minion2->setAggroRange(300);
    minion2->setMaxLife(100);
    minion2->setCurrentLife(100);
    addMonster(minion2);

    Minion *minion3 = new Minion(nextId(), &m_texture, mapState, bounds);
    minion3->setPosition(1400.0f, 450.0f);
    minion3->setHitBox(64, 128);
    minion3->setIdleMoveSpeed(1.0f);
    minion3->setAggroMoveSpeed(0.5f);
    minion3->setAggroRange(300);
    minion3->setMaxLife(100);
    minion3->setCurrentLife(100);
    addMonster(minion3);

    m_updater = new MinionUpdater(m_bounds, m_mapState, m_characterGraphics, m_monsters);
}

MinionManager::~MinionManager()
{
    delete m_updater;
}

void MinionManager::update()
{
    MonsterManager::update();

    m_updater->update();
}
