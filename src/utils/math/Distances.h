#ifndef SFMLDEMO_DISTANCES_H
#define SFMLDEMO_DISTANCES_H

#include <cmath>

class Distances
{
public:
    static bool isInRange(float x, float y, float dx, float dy, int range)
    {
        return sqrt(pow(x - dx, 2.0) + pow(y - dy, 2.0)) <= range;
    }
};

#endif //SFMLDEMO_DISTANCES_H
