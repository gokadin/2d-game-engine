#include "MapBounds.h"
#include "../../../components/map/Map.h"

MapBounds::MapBounds():
        m_width(0), m_height(0)
{}

void MapBounds::setBounds(std::vector<std::vector<int>> bounds)
{
    m_bounds = bounds;
    m_width = (int)bounds.size();
    m_height = (int)bounds[0].size();
}

void MapBounds::addBounds(float cx, float cy, int radius, int value)
{
    int leftI = (int)(cx - radius) / (NODE_SIZE * 4);
    int leftJ = (int)(cy) / (NODE_SIZE * 4);
    if (m_bounds[leftI][leftJ] == 0)
    {
        m_bounds[leftI][leftJ] = value;
    }
}

void MapBounds::removeBounds(float cx, float cy, int radius, int value)
{
    int leftI = (int)(cx - radius) / (NODE_SIZE * 4);
    int leftJ = (int)(cy) / (NODE_SIZE * 4);
    if (m_bounds[leftI][leftJ] == value)
    {
        m_bounds[leftI][leftJ] = 0;
    }
}

bool MapBounds::areIndexesOutOfBounds(int boundI, int boundJ)
{
    return boundI < 0 || boundJ < 0 || boundI >= m_width - 1 || boundJ >= m_height - 1;
}
