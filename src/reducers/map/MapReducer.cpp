#include "MapReducer.h"

MapReducer::MapReducer(GameState& state):
        Reducer(state)
{}

void MapReducer::process(action_types type)
{
    switch (type)
    {
        case action_types::CHARACTER_MOVE_UP:
            state.character.isMovingUp = true;
            break;
        case action_types::CHARACTER_STOP_UP:
            state.character.isMovingUp = false;
            break;
        case action_types::CHARACTER_MOVE_DOWN:
            state.character.isMovingDown = true;
            break;
        case action_types::CHARACTER_STOP_DOWN:
            state.character.isMovingDown = false;
            break;
        case action_types::CHARACTER_MOVE_RIGHT:
            state.character.isMovingRight = true;
            break;
        case action_types::CHARACTER_STOP_RIGHT:
            state.character.isMovingRight = false;
            break;
        case action_types::CHARACTER_MOVE_LEFT:
            state.character.isMovingLeft = true;
            break;
        case action_types::CHARACTER_STOP_LEFT:
            state.character.isMovingLeft = false;
            break;
    }
}
