#include "Monsters.h"
#include "../../monsters/common/zombie/ZombieManager.h"

Monsters::Monsters(MapState *mapState, MapBounds *bounds):
        m_mapState(mapState), m_bounds(bounds)
{
    m_monsterManagers.push_back(new ZombieManager(mapState, m_bounds));
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
    return m_monsterManagers[0]->findMonster(id);
}
