#include <iostream>
#include "ActionDispatcher.h"
#include "../reducers/map/MapReducer.h"
#include "../reducers/character/CharacterReducer.h"
#include "../reducers/skills/SkillActionDispatcher.h"

ActionDispatcher::ActionDispatcher(GameState& state):
        state(state)
{
    reducers.push_back(new MapReducer(state));
    reducers.push_back(new CharacterReducer(state));
    reducers.push_back(new SkillActionDispatcher(state));
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

void ActionDispatcher::dispatch(action_types type, int x, int y)
{
    for (int i = 0; i < reducers.size(); i++)
    {
        reducers[i]->process(type, x, y);
    }
}
