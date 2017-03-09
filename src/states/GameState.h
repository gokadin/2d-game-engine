#ifndef SFMLDEMO_GAMESTATE_H
#define SFMLDEMO_GAMESTATE_H

#include "MapState.h"
#include "CharacterState.h"
#include "ConfigState.h"

struct GameState
{
    GameState(int width, int height)
    {
        config.width = width;
        config.height = height;
    }

    ConfigState config;
    MapState map;
    CharacterState character;
};

#endif //SFMLDEMO_GAMESTATE_H
