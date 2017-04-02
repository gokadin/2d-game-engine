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
    int boundI = indexOfX(x);
    int boundJ = indexOfY(y);
    for (int i = 0; i < width / m_tileWidth; i++)
    {
        for (int j = 0; j < height / m_tileHeight; j++)
        {
            if (m_bounds[boundI + i][boundJ + j] == 0)
            {
                m_bounds[boundI + i][boundJ + j] = value;
            }
        }
    }
}

void MapBounds::removeBounds(float x, float y, int width, int height, int value)
{
    int boundI = indexOfX(x);
    int boundJ = indexOfY(y);
    for (int i = 0; i < width / m_tileWidth + 1; i++)
    {
        for (int j = 0; j < height / m_tileHeight + 1; j++)
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
    return areIndexesOutOfBounds(indexOfX(x), indexOfY(y));
}

bool MapBounds::areIndexesOutOfBounds(int boundI, int boundJ)
{
    return boundI < 0 || boundJ < 0 || boundI >= m_width - 1 || boundJ >= m_height - 1;
}
