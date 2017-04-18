#ifndef SFMLDEMO_CHARACTERSTATE_H
#define SFMLDEMO_CHARACTERSTATE_H

#include "../State.h"
#include "../../../core/Engine.h"
#include "../../../enums/common/EntityDirection.h"

class CharacterState : public State
{
public:
    CharacterState()
            : m_isMoving(false), m_isCasting(false), m_isMovementPaused(false), m_shouldStopOnPoint(false),
              m_direction(entity_direction::DOWN)
    {}

    inline bool isIdle() { return !m_isMoving && !m_isCasting; }
    inline bool isMoving() { return m_isMoving; }
    inline bool isCasting() { return m_isCasting; }
    inline bool isMovementPaused() { return m_isMovementPaused; }
    inline bool shouldStopOnPoint() { return m_shouldStopOnPoint; }
    inline entity_direction direction() { return m_direction; }

    inline void setIsCasting(bool value) { m_isCasting = value; }
    inline void setMovementPaused(bool value) { m_isMovementPaused = value; }
    inline void setDirection(entity_direction direction) { m_direction = direction; }

    void startMoving()
    {
        m_isMoving = true;
        m_shouldStopOnPoint = false;
    }

    void stopMoving()
    {
        m_isMoving = false;
    }

    void stopOnPoint(int x, int y)
    {
        m_shouldStopOnPoint = true;
    }

private:
    bool m_isMoving;
    bool m_isCasting;
    bool m_isMovementPaused;
    bool m_shouldStopOnPoint;
    entity_direction m_direction;
};

#endif //SFMLDEMO_CHARACTERSTATE_H
