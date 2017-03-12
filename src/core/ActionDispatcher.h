#ifndef SFMLDEMO_ACTIONDISPATCHER_H
#define SFMLDEMO_ACTIONDISPATCHER_H

#include <vector>
#include "../actions/ActionTypes.h"
#include "../reducers/Reducer.h"

class ActionDispatcher
{
public:
    ActionDispatcher(GameState& state);
    ~ActionDispatcher();

    void dispatch(action_types type, int x = 0, int y = 0);

private:
    GameState& state;
    std::vector<Reducer *> reducers;
};

#endif //SFMLDEMO_ACTIONDISPATCHER_H
