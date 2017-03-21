#include "Map.h"

Map::Map(sf::RenderWindow *window, CharacterStats *characterStats, CharacterGraphics *characterGraphics,
         CharacterState *characterState)
{
    m_graphics = new MapGraphics();
    m_state = new MapState();
    m_bounds = new MapBounds();
    m_renderer = new MapRenderer(m_graphics, m_state, m_bounds);
    m_updater = new MapUpdater(window, m_graphics, m_state, m_bounds , characterStats, characterGraphics, characterState);
}

Map::~Map()
{
    delete m_graphics;
    delete m_state;
    delete m_bounds;
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
