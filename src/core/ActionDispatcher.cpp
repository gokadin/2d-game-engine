#include <iostream>
#include "ActionDispatcher.h"
#include "../reducers/map/MapReducer.h"

ActionDispatcher::ActionDispatcher(GameState& state):
        state(state)
{
    reducers.push_back(new MapReducer(state));
}

ActionDispatcher::~ActionDispatcher()
{
    for (Reducer *reducer : reducers)
    {
        reducer = NULL;
        delete reducer;
    }
    reducers.clear();
}

void ActionDispatcher::dispatch(action_types type)
{
    for (int i = 0; i < reducers.size(); i++)
    {
        reducers[i]->process(type);
    }
}
