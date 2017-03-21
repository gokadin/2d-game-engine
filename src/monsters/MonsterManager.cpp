#include "MonsterManager.h"

MonsterManager::MonsterManager(int nextId, MapState *mapState, MapBounds *bounds):
        m_mapState(mapState), m_bounds(bounds), m_nextId(nextId)
{}

MonsterManager::~MonsterManager()
{
    for (std::pair<int, Monster *> pair : m_monsters)
    {
        pair.second = NULL;
        delete pair.second;
    }
    m_monsters.clear();
}

void MonsterManager::update()
{
    for (auto it = m_monsters.cbegin(); it != m_monsters.cend();)
    {
        if ((*it).second->isInactive())
        {
            it = m_monsters.erase(it);
            continue;
        }

        (*it).second->update();
        ++it;
    }
}

void MonsterManager::draw(sf::RenderWindow *window)
{
    for (std::pair<int, Monster *> pair : m_monsters)
    {
        pair.second->draw(window);
    }
}

void MonsterManager::addMonster(Monster *monster)
{
    m_monsters[monster->id()] = monster;
    monster->addToMap();
}

int MonsterManager::nextId()
{
    return m_nextId + 1;
}
