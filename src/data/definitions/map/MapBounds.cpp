#include "MapBounds.h"

MapBounds::MapBounds():
        m_width(0), m_height(0), m_tileWidth(0)
{}

void MapBounds::setBounds(std::vector<std::vector<int>> bounds)
{
    m_bounds = bounds;
    m_width = (int)bounds.size();
    m_height = (int)bounds[0].size();
}

void MapBounds::addBounds(float x, float y, int width, int height, int value)
{
    int boundI = indexFromPosition(x);
    int boundJ = indexFromPosition(y);
    for (int i = 0; i < width / m_tileWidth; i++)
    {
        for (int j = 0; j < height / m_tileWidth; j++)
        {
            m_bounds[boundI + i][boundJ + j] = value;
        }
    }
}

void MapBounds::removeBounds(float x, float y, int width, int height, int value)
{
    int boundI = indexFromPosition(x);
    int boundJ = indexFromPosition(y);
    for (int i = -1; i < width / m_tileWidth + 1; i++)
    {
        for (int j = -1; j < height / m_tileWidth + 1; j++)
        {
            if (m_bounds[boundI + i][boundJ + j] == value)
            {
                m_bounds[boundI + i][boundJ + j] = 0;
            }
        }
    }
}

bool MapBounds::isPositionOutOfBounds(float x, float y)
{
    return areIndexesOutOfBounds(indexFromPosition(x), indexFromPosition(y));
}

bool MapBounds::areIndexesOutOfBounds(int boundI, int boundJ)
{
    return boundI < 0 || boundJ < 0 || boundI >= m_width - 1 || boundJ >= m_height - 1;
}

int MapBounds::indexFromPosition(float xOry)
{
    return (int)(xOry / m_tileWidth);
}
