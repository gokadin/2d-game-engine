#include "MapUpdater.h"

MapUpdater::MapUpdater(GameState *state):
        Updater(state)
{}

void MapUpdater::update()
{
    move();
}

void MapUpdater::move()
{
    if (state->character.isMovingUp && !state->character.isMovingDown)
    {
        state->map.y -= 10;
    }

    if (state->character.isMovingDown && !state->character.isMovingUp)
    {
        state->map.y += 10;
    }

    if (state->character.isMovingRight && !state->character.isMovingLeft)
    {
        state->map.x += 10;
    }

    if (state->character.isMovingLeft && !state->character.isMovingRight)
    {
        state->map.x -= 10;
    }
}