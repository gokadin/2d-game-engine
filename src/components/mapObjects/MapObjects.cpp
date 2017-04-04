#include "MapObjects.h"
#include "objects/standingTorch/StandingTorch.h"

MapObjects::MapObjects(SortedRenderer *sortedRenderer, MapState *mapState):
        m_mapState(mapState)
{
    m_objects.push_back(new StandingTorch(sortedRenderer, mapState));
}

MapObjects::~MapObjects()
{
    for (auto *object : m_objects)
    {
        delete object;
    }
    m_objects.clear();
}

void MapObjects::update()
{
    for (auto *object : m_objects)
    {
        object->update();
    }
}

void MapObjects::draw(sf::RenderWindow *window)
{
    for (auto *object : m_objects)
    {
        object->draw(window);
    }
}
