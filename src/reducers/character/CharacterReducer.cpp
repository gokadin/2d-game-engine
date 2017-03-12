#include "CharacterReducer.h"

CharacterReducer::CharacterReducer(GameState &state):
        Reducer(state)
{}

void CharacterReducer::process(action_types type)
{
    switch (type)
    {
        case action_types::CHARACTER_MOVE_DOWN:

            break;
    }
}
