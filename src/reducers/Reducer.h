#ifndef SFMLDEMO_REDUCER_H
#define SFMLDEMO_REDUCER_H

#include "../updaters/Updater.h"
#include "../states/GameState.h"
#include "../actions/ActionTypes.h"

class Reducer
{
public:
    Reducer(GameState& state):
            state(state)
    {}

    virtual void process(action_types type, int x = 0, int y = 0) = 0;

protected:
    GameState& state;
};

#endif //SFMLDEMO_REDUCER_H
