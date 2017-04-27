#include "CollisionProcessor.h"
#include "../../utils/math/Coords.h"
#include "../../components/map/Map.h"

CollisionProcessor::CollisionProcessor(MapBounds *bounds, MapState *mapState, MapGraphics *mapGraphics)
        : m_bounds(bounds),
          m_mapState(mapState),
          m_mapGraphics(mapGraphics)
{}

void CollisionProcessor::processMovingTile(float cx, float cy, float radius, double angle, sf::Vector2f& collisionVector)
{
    if (angle >= THREE_QUARTER_PI || angle <= -THREE_QUARTER_PI)
    {
        processLeft(cx, cy, radius, collisionVector);
        return;
    }

    if (angle >= QUARTER_PI)
    {
        processBottom(cx, cy, radius, collisionVector);
        return;
    }

    if (angle <= -QUARTER_PI)
    {
        processTop(cx, cy, radius, collisionVector);
        return;
    }

    processRight(cx, cy, radius, collisionVector);
}

void CollisionProcessor::processLeft(float cx, float cy, float radius, sf::Vector2f &collisionVector)
{
    int topLeftValue = getTopLeftValue(cx, cy, radius);
    int bottomLeftValue = getBottomLeftValue(cx, cy, radius);

    if (topLeftValue > 0 && bottomLeftValue > 0)
    {
        collisionVector.x = 0;
        collisionVector.y = 0;
        return;
    }

    if (topLeftValue == 0 && bottomLeftValue > 0)
    {
        updateCollisionVector(UP_LEFT_ANGLE, collisionVector);
        return;
    }

    if (bottomLeftValue == 0 && topLeftValue > 0)
    {
        updateCollisionVector(DOWN_LEFT_ANGLE, collisionVector);
    }
}

void CollisionProcessor::processRight(float cx, float cy, float radius, sf::Vector2f &collisionVector)
{
    int topRightValue = getTopRightValue(cx, cy, radius);
    int bottomRightValue = getBottomRightValue(cx, cy, radius);

    if (bottomRightValue > 0 && topRightValue > 0)
    {
        collisionVector.x = 0;
        collisionVector.y = 0;
        return;
    }

    if (topRightValue == 0 && bottomRightValue > 0)
    {
        updateCollisionVector(UP_RIGHT_ANGLE, collisionVector);
        return;
    }

    if (bottomRightValue == 0 && topRightValue > 0)
    {
        updateCollisionVector(DOWN_RIGHT_ANGLE, collisionVector);
    }
}

void CollisionProcessor::processTop(float cx, float cy, float radius, sf::Vector2f &collisionVector)
{
    int topLeftValue = getTopLeftValue(cx, cy, radius);
    int topRightValue = getTopRightValue(cx, cy, radius);

    if (topLeftValue > 0 && topRightValue > 0)
    {
        collisionVector.x = 0;
        collisionVector.y = 0;
        return;
    }

    if (topLeftValue == 0 && topRightValue > 0)
    {
        updateCollisionVector(UP_LEFT_ANGLE, collisionVector);
        return;
    }

    if (topRightValue == 0 && topLeftValue > 0)
    {
        updateCollisionVector(UP_RIGHT_ANGLE, collisionVector);
    }
}

void CollisionProcessor::processBottom(float cx, float cy, float radius, sf::Vector2f &collisionVector)
{
    int bottomLeftValue = getBottomLeftValue(cx, cy, radius);
    int bottomRightValue = getBottomRightValue(cx, cy, radius);

    if (bottomLeftValue > 0 && bottomRightValue > 0)
    {
        collisionVector.x = 0;
        collisionVector.y = 0;
        return;
    }

    if (bottomLeftValue == 0 && bottomRightValue > 0)
    {
        updateCollisionVector(DOWN_LEFT_ANGLE, collisionVector);
        return;
    }

    if (bottomRightValue == 0 && bottomLeftValue > 0)
    {
        updateCollisionVector(DOWN_RIGHT_ANGLE, collisionVector);
    }
}

void CollisionProcessor::updateCollisionVector(double angle, sf::Vector2f &collisionVector)
{
    collisionVector.x = (float)cos(angle);
    collisionVector.y = (float)sin(angle);
}

int CollisionProcessor::getBottomRightValue(float cx, float cy, float radius)
{
    sf::Vector2i coordsDRB((int)cx + BOUND_CHECK_HEAD_ROOM_OFFSET, (int)(cy + radius));
    sf::Vector2i coordsDRT((int)(cx + radius * 2), (int)cy + BOUND_CHECK_HEAD_ROOM_OFFSET);
    return getTileValue(coordsDRB, coordsDRT);
}

int CollisionProcessor::getBottomLeftValue(float cx, float cy, float radius)
{
    sf::Vector2i coordsDLB((int)cx - BOUND_CHECK_HEAD_ROOM_OFFSET, (int)(cy + radius));
    sf::Vector2i coordsDLT((int)(cx - radius * 2), (int)cy + BOUND_CHECK_HEAD_ROOM_OFFSET);
    return getTileValue(coordsDLB, coordsDLT);
}

int CollisionProcessor::getTopLeftValue(float cx, float cy, float radius)
{
    sf::Vector2i coordsTLT((int)cx - BOUND_CHECK_HEAD_ROOM_OFFSET, (int)(cy - radius));
    sf::Vector2i coordsTLB((int)(cx - radius * 2), (int)cy - BOUND_CHECK_HEAD_ROOM_OFFSET);
    return getTileValue(coordsTLT, coordsTLB);
}

int CollisionProcessor::getTopRightValue(float cx, float cy, float radius)
{
    sf::Vector2i coordsTRT((int)cx + BOUND_CHECK_HEAD_ROOM_OFFSET, (int)(cy - radius));
    sf::Vector2i coordsTRB((int)(cx + radius * 2), (int)cy - BOUND_CHECK_HEAD_ROOM_OFFSET);
    return getTileValue(coordsTRT, coordsTRB);
}

int CollisionProcessor::getTileValue(sf::Vector2i &first, sf::Vector2i &second)
{
    Coords::fromIsometric(first, m_mapState->x() - m_mapState->isometricOffsetX(), m_mapState->y());
    first.x /= NODE_SIZE;
    first.y /= NODE_SIZE;

    Coords::fromIsometric(second, m_mapState->x() - m_mapState->isometricOffsetX(), m_mapState->y());
    second.x /= NODE_SIZE;
    second.y /= NODE_SIZE;

    int value = m_bounds->get(first.x, first.y);
    if (m_bounds->get(second.x, second.y) > value)
    {
        return m_bounds->get(second.x, second.y);
    }

    return value;
}
