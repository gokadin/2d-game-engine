#ifndef SFMLDEMO_MAPDATA_H
#define SFMLDEMO_MAPDATA_H

#include <vector>

class MapBounds
{
public:
    MapBounds();

    inline int width() { return m_width; }
    inline int height() { return m_height; }
    inline int get(int i, int j) { return m_bounds[i][j]; }

    void setBounds(std::vector<std::vector<int>> bounds);

    void addBounds(float cx, float cy, int radius, int value);
    void removeBounds(float cx, float cy, int radius, int value);
    bool areIndexesOutOfBounds(int boundI, int boundJ);

private:
    std::vector<std::vector<int>> m_bounds;
    int m_width;
    int m_height;
};

#endif //SFMLDEMO_MAPDATA_H
