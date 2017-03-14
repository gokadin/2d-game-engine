#include "Map.h"

Map::Map()
{
    m_graphics = new MapGraphics();
    m_state = new MapState();
}

Map::~Map()
{
    delete m_graphics;
    delete m_state;
}

void Map::update()
{

}

void Map::draw(sf::RenderWindow *window)
{

}
