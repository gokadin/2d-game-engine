#include <iostream>
#include "SkillActionDispatcher.h"
#include "fireball/FireballReducer.h"

SkillActionDispatcher::SkillActionDispatcher(GameState &state):
        Reducer(state)
{
    skillReducers[skill_names::FIREBALL] = new FireballReducer(state);
}

SkillActionDispatcher::~SkillActionDispatcher()
{
    for (std::pair<skill_names, SkillReducer *> pair : skillReducers)
    {
        pair.second = NULL;
        delete pair.second;
    }
    skillReducers.clear();
}

void SkillActionDispatcher::process(action_types type, int x, int y)
{
    switch (type)
    {
        case action_types::USE_SKILL_0:
            // later
            // catch a left mouse events instead of use_skill_0
            // decide in reducer if it should be a skill or something else based on cursor position (ex: inventory vs map)
            // also check if it can activate (mana, etc...)
            // check if no skill assigned
            if (!state.character.isCasting)
            {
                skillReducers[state.character.skills[0].name]->process(0, x, y);
            }
            break;
    }
}


