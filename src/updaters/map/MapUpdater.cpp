#include "MapUpdater.h"

MapUpdater::MapUpdater(GameState *state):
        Updater(state)
{}

void MapUpdater::update()
{
    if (state->character.isMovingUp)
    {
        state->map.offsetY -= 10;
    }

    if (state->character.isMovingDown)
    {
        state->map.offsetY += 10;
    }

    if (state->character.isMovingRight)
    {
        state->map.offsetX += 10;
    }

    if (state->character.isMovingLeft)
    {
        state->map.offsetX -= 10;
    }
}
