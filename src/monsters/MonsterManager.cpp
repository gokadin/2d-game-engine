#include "MonsterManager.h"

MonsterManager::MonsterManager(int nextId, MapState *mapState, MapBounds *bounds, CharacterGraphics *characterGraphics):
        m_mapState(mapState), m_bounds(bounds), m_nextId(nextId), m_characterGraphics(characterGraphics)
{
    m_healthBarBackground.setSize(sf::Vector2f(HEALTH_BAR_WIDTH, HEALTH_BAR_HEIGHT));
    m_healthBarBackground.setFillColor(sf::Color(50, 50, 50));
    m_healthBarBackground.setOutlineThickness(1);
    m_healthBarBackground.setOutlineColor(sf::Color(100, 100, 100));

    m_healthBarForeground.setSize(sf::Vector2f(HEALTH_BAR_WIDTH, HEALTH_BAR_HEIGHT));
    m_healthBarForeground.setFillColor(sf::Color::Green);
}

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

        if (pair.second->isAlive())
        {
            drawHealthBar(window, pair.second);
        }
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

void MonsterManager::drawHealthBar(sf::RenderWindow *window, Monster *monster)
{
    m_healthBarBackground.setPosition(monster->x() - m_mapState->x() - HEALTH_BAR_WIDTH / 2,
                                      monster->y() - m_mapState->y() - HEALTH_BAR_BOTTOM_MARGIN);
    m_healthBarForeground.setPosition(m_healthBarBackground.getPosition().x, m_healthBarBackground.getPosition().y);
    m_healthBarForeground.setSize(sf::Vector2f(monster->currentLife() * HEALTH_BAR_WIDTH / monster->maxLife(),
                                               HEALTH_BAR_HEIGHT));
    window->draw(m_healthBarBackground);
    window->draw(m_healthBarForeground);
}
