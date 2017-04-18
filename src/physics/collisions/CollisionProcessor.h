#ifndef SFMLDEMO_COLLISIONS_H
#define SFMLDEMO_COLLISIONS_H

#include "../../data/definitions/map/MapBounds.h"

class CollisionProcessor
{
public:
    CollisionProcessor(MapBounds *bounds);

private:
    MapBounds *m_bounds;
};

#endif //SFMLDEMO_COLLISIONS_H
