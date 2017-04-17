#ifndef SFMLDEMO_MAPSTATE_H
#define SFMLDEMO_MAPSTATE_H

#include "../State.h"
#include "../../../core/Engine.h"

class MapState : public State
{
public:
    inline float cx() { return m_x + Engine::HALF_SCREEN_WIDTH; }
    inline float cy() { return m_y + Engine::HALF_SCREEN_HEIGHT; }
};

#endif //SFMLDEMO_MAPSTATE_H
