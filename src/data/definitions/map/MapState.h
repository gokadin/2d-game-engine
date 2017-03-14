#ifndef SFMLDEMO_MAPSTATE_H
#define SFMLDEMO_MAPSTATE_H

#include "../State.h"

class MapState : public State
{
public:
    inline bool isMoving() { return m_isMoving; }
    inline bool isMovementPaused() { return m_isMovementPaused; }

    inline void setIsMoving(bool value) { m_isMoving = value; }

private:
    bool m_isMoving;
    bool m_isMovementPaused;
};

#endif //SFMLDEMO_MAPSTATE_H
