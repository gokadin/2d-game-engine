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
