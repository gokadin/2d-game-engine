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

    int charLeft = state.map.x - state.character.boxWidth / 2;
    int charTop = state.map.y - state.character.boxHeight / 2 - state.character.moveSpeed;
    for (int i = 0; i < state.character.boxWidth; i++)
    {
        if (state.map.bounds[charTop][charLeft + i] == 1)
        {
            return;
        }
    }

    state.map.y -= state.character.moveSpeed;
}

void MapUpdater::moveDown()
{
    if (!state.character.isMovingDown || state.character.isMovingUp)
    {
        return;
    }

    int charLeft = state.map.x - state.character.boxWidth / 2;
    int charBottom = state.map.y + state.character.boxHeight / 2 + state.character.moveSpeed;
    for (int i = 0; i < state.character.boxWidth; i++)
    {
        if (state.map.bounds[charBottom][charLeft + i] == 1)
        {
            return;
        }
    }

    state.map.y += state.character.moveSpeed;
}

void MapUpdater::moveRight()
{
    if (!state.character.isMovingRight || state.character.isMovingLeft)
    {
        return;
    }

    int charTop = state.map.y - state.character.boxHeight / 2;
    int charRight = state.map.x + state.character.boxWidth / 2 + state.character.moveSpeed;
    for (int i = 0; i < state.character.boxHeight; i++)
    {
        if (state.map.bounds[charTop + i][charRight] == 1)
        {
            return;
        }
    }

    state.map.x += state.character.moveSpeed;
}

void MapUpdater::moveLeft()
{
    if (!state.character.isMovingLeft || state.character.isMovingRight)
    {
        return;
    }

    int charTop = state.map.y - state.character.boxHeight / 2;
    int charLeft = state.map.x - state.character.boxWidth / 2 - state.character.moveSpeed;
    for (int i = 0; i < state.character.boxHeight; i++)
    {
        if (state.map.bounds[charTop + i][charLeft] == 1)
        {
            return;
        }
    }

    state.map.x -= state.character.moveSpeed;
}