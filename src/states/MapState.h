#ifndef SFMLDEMO_MAPSTATE_H
#define SFMLDEMO_MAPSTATE_H

#include <vector>

struct MapState
{
    int x;
    int y;
    std::vector<std::vector<int>> bounds;
};

#endif //SFMLDEMO_MAPSTATE_H
