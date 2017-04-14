#include "Monsters.h"
#include "../../monsters/common/zombie/ZombieManager.h"
#include "../../monsters/common/summoner/SummonerManager.h"
#include "../../monsters/common/minion/MinionManager.h"

Monsters::Monsters(MapState *mapState, MapBounds *bounds, CharacterGraphics *characterGraphics):
        m_mapState(mapState), m_bounds(bounds), m_characterGraphics(characterGraphics)
{
    m_monsterManagers.push_back(new ZombieManager(1000, mapState, m_bounds, m_characterGraphics));
    m_monsterManagers[m_monsterManagers.size() - 1]->subscribe(this);
    MonsterManager *minionManager = new MinionManager(2000, mapState, m_bounds, m_characterGraphics);
    m_monsterManagers.push_back(minionManager);
    m_monsterManagers[m_monsterManagers.size() - 1]->subscribe(this);
    m_monsterManagers.push_back(new SummonerManager(3000, mapState, m_bounds, m_characterGraphics, minionManager));
    m_monsterManagers[m_monsterManagers.size() - 1]->subscribe(this);
}

Monsters::~Monsters()
{
    for (MonsterManager *monsterManager : m_monsterManagers)
    {
        monsterManager = NULL;
        delete monsterManager;
    }
    m_monsterManagers.clear();
}

void Monsters::update()
{
    for (MonsterManager *monsterManager : m_monsterManagers)
    {
        monsterManager->update();
    }
}

void Monsters::draw(sf::RenderWindow *window)
{
    for (MonsterManager *monsterManager : m_monsterManagers)
    {
        monsterManager->draw(window);
    }
}

Monster *Monsters::findMonster(int id)
{
    return m_monsterManagers[id / 1000 - 1]->findMonster(id);
}

void Monsters::handleEvent(std::shared_ptr<Event> event)
{
    switch (event->type())
    {
        case event_type::MONSTER_DIED:
            notifyObservers(event);
            break;
    }
}
