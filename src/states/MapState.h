#ifndef SFMLDEMO_MAPSTATE_H
#define SFMLDEMO_MAPSTATE_H

#include <vector>
#include <string>

struct MapState
{
    int width;
    int height;
    int cx;
    int cy;
    std::string texture;
    std::vector<std::vector<int>> bounds;
};

#endif //SFMLDEMO_MAPSTATE_H
