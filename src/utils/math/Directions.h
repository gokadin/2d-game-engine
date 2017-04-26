#ifndef SFMLDEMO_DIRECTIONS_H
#define SFMLDEMO_DIRECTIONS_H

#include <math.h>
#include "../../enums/common/EntityDirection.h"

#define HALF_PI (M_PI / 2)
#define QUARTER_PI (HALF_PI / 2)
#define THREE_QUARTER_PI (M_PI - QUARTER_PI)
#define ONE_SIXTH_PI (M_PI / 6)
#define ONE_THIRD_PI (M_PI / 3)
#define TWO_THIRDS_PI (ONE_THIRD_PI * 2)
#define FIVE_SIXTH_PI (ONE_SIXTH_PI * 5)

class Directions
{
public:
    static entity_direction directionFromAngle(double angle)
    {
        if (angle >= FIVE_SIXTH_PI || angle <= -FIVE_SIXTH_PI)
        {
            return entity_direction::LEFT;
        }

        if (angle >= TWO_THIRDS_PI)
        {
            return entity_direction::DOWN_LEFT;
        }

        if (angle >= ONE_THIRD_PI)
        {
            return entity_direction::DOWN;
        }

        if (angle >= ONE_SIXTH_PI)
        {
            return entity_direction::DOWN_RIGHT;
        }

        if (angle <= -TWO_THIRDS_PI)
        {
            return entity_direction::UP_LEFT;
        }

        if (angle <= -ONE_THIRD_PI)
        {
            return entity_direction::UP;
        }

        if (angle <= -ONE_SIXTH_PI)
        {
            return entity_direction::UP_RIGHT;
        }

        return entity_direction::DOWN_LEFT;
    }
};

#endif //SFMLDEMO_DIRECTIONS_H
