#ifndef SFMLDEMO_GAMESTATE_H
#define SFMLDEMO_GAMESTATE_H

#include "MapState.h"
#include "CharacterState.h"
#include "ConfigState.h"
#include "SaveState.h"
#include "MonsterState.h"

struct GameState
{
    SaveState save;
    ConfigState config;
    MapState map;
    CharacterState character;
    std::vector<MonsterState> monsters;
};

#endif //SFMLDEMO_GAMESTATE_H
