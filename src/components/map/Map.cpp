#include "Map.h"

Map::Map(sf::RenderWindow *window, CharacterStats *characterStats)
{
    m_graphics = new MapGraphics();
    m_state = new MapState();
    m_renderer = new MapRenderer(m_graphics, m_state);
    m_updater = new MapUpdater(window, m_graphics, m_state, characterStats);
}

Map::~Map()
{
    delete m_graphics;
    delete m_state;
    delete m_renderer;
    delete m_updater;
}

void Map::update()
{
    m_updater->update();
}

void Map::draw(sf::RenderWindow *window)
{
    m_renderer->draw(window);
}

void Map::startMoving()
{
    m_state->startMoving();
}

void Map::stopMovingOnPoint(int x, int y)
{
    m_state->stopOnPoint(x, y);
}
