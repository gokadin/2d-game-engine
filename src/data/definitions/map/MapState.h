#ifndef SFMLDEMO_MAPSTATE_H
#define SFMLDEMO_MAPSTATE_H

#include "../State.h"
#include "../../../core/Engine.h"

class MapState : public State
{
public:
    MapState():
            m_isMoving(false), m_isMovementPaused(false),
            m_shouldStopOnPoint(false), m_lastPointX(0),
            m_lastPointY(0)
    {}

    inline bool isMoving() { return m_isMoving; }
    inline bool isMovementPaused() { return m_isMovementPaused; }
    inline bool shouldStopOnPoint() { return m_shouldStopOnPoint; }
    inline float lastPointX() { return m_lastPointX; }
    inline float lastPointY() { return m_lastPointY; }
    inline float cx() { return m_x + Engine::CX; }
    inline float cy() { return m_y + Engine::CY; }

    void startMoving()
    {
        m_isMoving = true;
        m_shouldStopOnPoint = false;
        m_lastPointX = 0;
        m_lastPointY = 0;
    }

    void stopMoving()
    {
        m_isMoving = false;
    }

    void stopOnPoint(int x, int y)
    {
        m_shouldStopOnPoint = true;
        m_lastPointX = m_x + x - Engine::CX;
        m_lastPointY = m_y + y - Engine::CY;
    }

private:
    bool m_isMoving;
    bool m_isMovementPaused;
    bool m_shouldStopOnPoint;
    float m_lastPointX;
    float m_lastPointY;
};

#endif //SFMLDEMO_MAPSTATE_H
