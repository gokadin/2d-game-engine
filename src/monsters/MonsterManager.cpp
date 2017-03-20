#include "MonsterManager.h"

MonsterManager::MonsterManager(MapState *mapState, std::vector<std::vector<int>> *bounds):
        m_mapState(mapState), m_bounds(bounds), m_nextId(1000)
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
    for (std::pair<int, Monster *> pair : m_monsters)
    {
        pair.second->update();
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
    m_nextId++;

    m_monsters[m_nextId] = monster;
    int boundI = 1100 / 16;
    int boundJ = 650 / 16;
    (*m_bounds)[boundI][boundJ] = m_nextId;
    (*m_bounds)[boundI + 1][boundJ] = m_nextId;
    (*m_bounds)[boundI + 1][boundJ + 1] = m_nextId;
    (*m_bounds)[boundI][boundJ + 1] = m_nextId;
}
