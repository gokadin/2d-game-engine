#include "SummonerManager.h"
#include "Summoner.h"

SummonerManager::SummonerManager(int baseId, MapState *mapState, MapBounds *bounds,
                                 CharacterGraphics *characterGraphics, MonsterManager *minionManager):
        MonsterManager(baseId, mapState, bounds, characterGraphics), m_minionManager(minionManager)
{
    if (!m_texture.loadFromFile("../src/storage/game/monsters/common/summoner/texture.png"))
    {
        std::cout << "Could not load texture." << std::endl;
    }

    Summoner *summoner = new Summoner(nextId(), &m_texture, mapState, bounds);
    summoner->setPosition(1200.0f, 850.0f);
    summoner->setHitBox(64, 128);
    summoner->setIdleMoveSpeed(1.5);
    summoner->setAggroMoveSpeed(2.5);
    summoner->setAggroRange(100);
    summoner->setMaxLife(100);
    summoner->setCurrentLife(100);
    addMonster(summoner);

    m_updater = new SummonerUpdater(m_bounds, m_mapState, m_characterGraphics, m_monsters, m_minionManager);
}

SummonerManager::~SummonerManager()
{
    delete m_updater;
}

void SummonerManager::update()
{
    MonsterManager::update();

    m_updater->update();
}
