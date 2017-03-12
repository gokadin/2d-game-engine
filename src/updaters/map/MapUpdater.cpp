#include <iostream>
#include "MapUpdater.h"

MapUpdater::MapUpdater(GameState& state):
        Updater(state)
{}

void MapUpdater::update()
{
    int oldX = state.map.x;
    int oldY = state.map.y;

    move();

    if (state.map.x != oldX || state.map.y != oldY)
    {
        std::cout << "X = " << state.map.x << "   Y = " << state.map.y << std::endl;
    }
}

void MapUpdater::move()
{
    moveUp();
    moveDown();
    moveRight();
    moveLeft();
}

void MapUpdater::moveUp()
{
    if (!state.character.isMovingUp || state.character.isMovingDown)
    {
        return;
    }

    int charTop = state.map.y - state.character.legRoom - state.character.moveSpeed;
    bool leftFree = state.map.bounds[charTop][state.map.x - state.character.boxWidth / 2] == 0;
    bool rightFree = state.map.bounds[charTop][state.map.x + state.character.boxWidth / 2] == 0;
    if (!leftFree && !rightFree)
    {
        return;
    }

    if (leftFree && !rightFree)
    {
        state.map.x -= state.character.moveSpeed;
    }
    else if (!leftFree)
    {
        state.map.x += state.character.moveSpeed;
    }

    state.map.y -= state.character.moveSpeed;
}

void MapUpdater::moveDown()
{
    if (!state.character.isMovingDown || state.character.isMovingUp)
    {
        return;
    }

    int charBottom = state.map.y + state.character.moveSpeed;
    bool leftFree = state.map.bounds[charBottom][state.map.x - state.character.boxWidth / 2] == 0;
    bool rightFree = state.map.bounds[charBottom][state.map.x + state.character.boxWidth / 2] == 0;
    if (!leftFree && !rightFree)
    {
        return;
    }

    if (leftFree && !rightFree)
    {
        state.map.x -= state.character.moveSpeed;
    }
    else if (!leftFree)
    {
        state.map.x += state.character.moveSpeed;
    }

    state.map.y += state.character.moveSpeed;
}

void MapUpdater::moveRight()
{
    if (!state.character.isMovingRight || state.character.isMovingLeft)
    {
        return;
    }

    int charRight = state.map.x + state.character.boxWidth / 2 + state.character.moveSpeed;
    bool topFree = state.map.bounds[state.map.y - state.character.legRoom][charRight] == 0;
    bool bottomFree = state.map.bounds[state.map.y][charRight] == 0;
    if (!topFree && !bottomFree)
    {
        return;
    }

    if (topFree && !bottomFree)
    {
        state.map.y -= state.character.moveSpeed;
    }
    else if (!topFree)
    {
        state.map.y += state.character.moveSpeed;
    }

    state.map.x += state.character.moveSpeed;
}

void MapUpdater::moveLeft()
{
    if (!state.character.isMovingLeft || state.character.isMovingRight)
    {
        return;
    }

    int charLeft = state.map.x - state.character.boxWidth / 2 - state.character.moveSpeed;
    bool topFree = state.map.bounds[state.map.y - state.character.legRoom][charLeft] == 0;
    bool bottomFree = state.map.bounds[state.map.y][charLeft] == 0;
    if (!topFree && !bottomFree)
    {
        return;
    }

    if (topFree && !bottomFree)
    {
        state.map.y -= state.character.moveSpeed;
    }
    else if (!topFree)
    {
        state.map.y += state.character.moveSpeed;
    }

    state.map.x -= state.character.moveSpeed;
}