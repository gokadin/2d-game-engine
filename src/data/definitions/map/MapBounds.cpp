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
    std::cout << leftI << " " << leftJ << std::endl;

    if (m_bounds[leftI][leftJ] == 0)
    {
        m_bounds[leftI][leftJ] = value;
    }

//    int boundI = indexOfX(x);
//    int boundJ = indexOfY(y);
//    for (int i = 0; i < radius / m_tileWidth; i++)
//    {
//        for (int j = 0; j < height / m_tileHeight; j++)
//        {
//            if (m_bounds[boundI + i][boundJ + j] == 0)
//            {
//                m_bounds[boundI + i][boundJ + j] = value;
//            }
//        }
//    }
}

void MapBounds::removeBounds(float cx, float cy, int radius, int value)
{
    int leftI = (int)(cx - radius) / (NODE_SIZE * 4);
    int leftJ = (int)(cy) / (NODE_SIZE * 4);

    if (m_bounds[leftI][leftJ] == value)
    {
        m_bounds[leftI][leftJ] = 0;
    }

//    int boundI = indexOfX(x);
//    int boundJ = indexOfY(y);
//    for (int i = 0; i < width / m_tileWidth + 1; i++)
//    {
//        for (int j = 0; j < height / m_tileHeight + 1; j++)
//        {
//            if (m_bounds[boundI + i][boundJ + j] == value)
//            {
//                m_bounds[boundI + i][boundJ + j] = 0;
//            }
//        }
//    }
}

bool MapBounds::areIndexesOutOfBounds(int boundI, int boundJ)
{
    return boundI < 0 || boundJ < 0 || boundI >= m_width - 1 || boundJ >= m_height - 1;
}
