#ifndef SFMLDEMO_GAMESTATE_H
#define SFMLDEMO_GAMESTATE_H

#include "MapState.h"
#include "CharacterState.h"
#include "ConfigState.h"

struct GameState
{
    ConfigState config;
    MapState map;
    CharacterState character;
};

#endif //SFMLDEMO_GAMESTATE_H
