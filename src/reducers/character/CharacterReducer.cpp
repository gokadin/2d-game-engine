#include "CharacterReducer.h"

CharacterReducer::CharacterReducer(GameState &state):
        Reducer(state)
{}

void CharacterReducer::process(action_types type, int x, int y)
{
    switch (type)
    {
        case action_types::USE_SKILL_0:
            // later
            // catch a left mouse events instead of use_skill_0
            // decide in reducer if it should be a skill or something else based on cursor position (ex: inventory vs map)
            // also check if it can activate (mana, etc...)
            // check if no skill assigned
            //state.character.skills[0].projectiles
            break;
    }
}
