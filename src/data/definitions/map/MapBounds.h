#ifndef SFMLDEMO_MAPDATA_H
#define SFMLDEMO_MAPDATA_H

#include <vector>

class MapBounds
{
public:
    MapBounds();

    inline int width() { return m_width; }
    inline int height() { return m_height; }
    inline int tileWidth() { return m_tileWidth; }
    inline int tileHeight() { return m_tileHeight; }
    inline int get(int i, int j) { return m_bounds[i][j]; }

    inline void setTileWidth(int tileWidth)
    {
        m_tileWidth = tileWidth;
        m_tileHeight = tileWidth / 2;
    }
    void setBounds(std::vector<std::vector<int>> bounds);

    void addBounds(float x, float y, int width, int height, int value);
    void removeBounds(float x, float y, int width, int height, int value);
    bool isPositionOutOfBounds(float x, float y);
    bool areIndexesOutOfBounds(int boundI, int boundJ);
    int indexFromPosition(float xOry);

private:
    std::vector<std::vector<int>> m_bounds;
    int m_width;
    int m_height;
    int m_tileWidth;
    int m_tileHeight;
};

#endif //SFMLDEMO_MAPDATA_H
