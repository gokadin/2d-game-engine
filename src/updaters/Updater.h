#ifndef SFMLDEMO_UPDATER_H
#define SFMLDEMO_UPDATER_H

#include "../states/GameState.h"

class Updater
{
public:
    Updater(GameState *state):
            state(state)
    {}

    virtual void update() = 0;

protected:
    GameState *state;
};

#endif //SFMLDEMO_UPDATER_H
