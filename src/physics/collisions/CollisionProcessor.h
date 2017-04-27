#ifndef SFMLDEMO_COLLISIONS_H
#define SFMLDEMO_COLLISIONS_H

#include <cmath>
#include <SFML/System.hpp>
#include "../../data/definitions/map/MapBounds.h"
#include "../../data/definitions/map/MapState.h"
#include "../../data/definitions/map/MapGraphics.h"

#define HALF_PI (M_PI / 2)
#define QUARTER_PI (HALF_PI / 2)
#define THREE_QUARTER_PI (M_PI - QUARTER_PI)
#define ONE_SIXTH_PI (M_PI / 6)
#define ONE_THIRD_PI (M_PI / 3)
#define TWO_THIRDS_PI (ONE_THIRD_PI * 2)
#define FIVE_SIXTH_PI (ONE_SIXTH_PI * 5)

class CollisionProcessor
{
public:
    CollisionProcessor(MapBounds *bounds, MapState *mapState, MapGraphics *mapGraphics);

    void processMovingTile(float cx, float cy, float radius, double angle, sf::Vector2f& collisionVector);

private:
    const double DOWN_RIGHT_ANGLE = atan2(1.0, 2.0);
    const double DOWN_LEFT_ANGLE = atan2(1.0, -2.0);
    const double UP_RIGHT_ANGLE = atan2(-1.0, 2.0);
    const double UP_LEFT_ANGLE = atan2(-1.0, -2.0);
    const int BOUND_CHECK_HEAD_ROOM_OFFSET = 4;

    MapBounds *m_bounds;
    MapState *m_mapState;
    MapGraphics *m_mapGraphics;

    void processLeft(float cx, float cy, float radius, sf::Vector2f& collisionVector);
    void processRight(float cx, float cy, float radius, sf::Vector2f& collisionVector);
    void processTop(float cx, float cy, float radius, sf::Vector2f& collisionVector);
    void processBottom(float cx, float cy, float radius, sf::Vector2f& collisionVector);
    int getBottomRightValue(float cx, float cy, float radius);
    int getBottomLeftValue(float cx, float cy, float radius);
    int getTopLeftValue(float cx, float cy, float radius);
    int getTopRightValue(float cx, float cy, float radius);
    int getTileValue(sf::Vector2i& first, sf::Vector2i& second);
    void updateCollisionVector(double angle, sf::Vector2f& collisionVector);
};

#endif //SFMLDEMO_COLLISIONS_H
