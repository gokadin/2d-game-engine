//#include <iostream>
//#include "MapUpdater.h"
//
//MapUpdater::MapUpdater(GameState& state):
//        Updater(state)
//{}
//
//void MapUpdater::update()
//{
//    int oldX = state.map.cx;
//    int oldY = state.map.cy;
//
//    move();
//
//    if (state.map.cx != oldX || state.map.cy != oldY)
//    {
//        std::cout << "X = " << state.map.cx << "   Y = " << state.map.cy << std::endl;
//    }
//}
//
//void MapUpdater::move()
//{
//    if (!state.character.pauseMovement)
//    {
//        moveUp();
//        moveDown();
//        moveRight();
//        moveLeft();
//    }
//}
//
//void MapUpdater::moveUp()
//{
//    if (!state.character.isMovingUp || state.character.isMovingDown)
//    {
//        return;
//    }
//
//    int charTop = state.map.cy - state.character.legRoom - state.character.moveSpeed;
//    bool leftFree = state.map.bounds[charTop][state.map.cx - state.character.boxWidth / 2] == 0;
//    bool rightFree = state.map.bounds[charTop][state.map.cx + state.character.boxWidth / 2] == 0;
//    if (!leftFree && !rightFree)
//    {
//        return;
//    }
//
//    if (leftFree && !rightFree)
//    {
//        state.map.cx -= state.character.moveSpeed;
//    }
//    else if (!leftFree)
//    {
//        state.map.cx += state.character.moveSpeed;
//    }
//
//    state.map.cy -= state.character.moveSpeed;
//}
//
//void MapUpdater::moveDown()
//{
//    if (!state.character.isMovingDown || state.character.isMovingUp)
//    {
//        return;
//    }
//
//    int charBottom = state.map.cy + state.character.moveSpeed;
//    bool leftFree = state.map.bounds[charBottom][state.map.cx - state.character.boxWidth / 2] == 0;
//    bool rightFree = state.map.bounds[charBottom][state.map.cx + state.character.boxWidth / 2] == 0;
//    if (!leftFree && !rightFree)
//    {
//        return;
//    }
//
//    if (leftFree && !rightFree)
//    {
//        state.map.cx -= state.character.moveSpeed;
//    }
//    else if (!leftFree)
//    {
//        state.map.cx += state.character.moveSpeed;
//    }
//
//    state.map.cy += state.character.moveSpeed;
//}
//
//void MapUpdater::moveRight()
//{
//    if (!state.character.isMovingRight || state.character.isMovingLeft)
//    {
//        return;
//    }
//
//    int charRight = state.map.cx + state.character.boxWidth / 2 + state.character.moveSpeed;
//    bool topFree = state.map.bounds[state.map.cy - state.character.legRoom][charRight] == 0;
//    bool bottomFree = state.map.bounds[state.map.cy][charRight] == 0;
//    if (!topFree && !bottomFree)
//    {
//        return;
//    }
//
//    if (topFree && !bottomFree)
//    {
//        state.map.cy -= state.character.moveSpeed;
//    }
//    else if (!topFree)
//    {
//        state.map.cy += state.character.moveSpeed;
//    }
//
//    state.map.cx += state.character.moveSpeed;
//}
//
//void MapUpdater::moveLeft()
//{
//    if (!state.character.isMovingLeft || state.character.isMovingRight)
//    {
//        return;
//    }
//
//    int charLeft = state.map.cx - state.character.boxWidth / 2 - state.character.moveSpeed;
//    bool topFree = state.map.bounds[state.map.cy - state.character.legRoom][charLeft] == 0;
//    bool bottomFree = state.map.bounds[state.map.cy][charLeft] == 0;
//    if (!topFree && !bottomFree)
//    {
//        return;
//    }
//
//    if (topFree && !bottomFree)
//    {
//        state.map.cy -= state.character.moveSpeed;
//    }
//    else if (!topFree)
//    {
//        state.map.cy += state.character.moveSpeed;
//    }
//
//    state.map.cx -= state.character.moveSpeed;
//}