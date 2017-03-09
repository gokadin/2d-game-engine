#ifndef SFMLDEMO_GAMESTATE_H
#define SFMLDEMO_GAMESTATE_H

#include "MapState.h"

class GameState
{
public:
    GameState():
            mapState(new MapState())
    {}

    ~GameState()
    {
        delete mapState;
    }

    inline MapState* getMapState() { return mapState; }

private:
    MapState *mapState;
};

#endif //SFMLDEMO_GAMESTATE_H
