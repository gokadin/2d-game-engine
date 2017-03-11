#ifndef SFMLDEMO_PROVIDER_H
#define SFMLDEMO_PROVIDER_H

#include "../../states/GameState.h"
#include "../persistence/SaveReader.h"

const std::string GAME_STORAGE_ROOT = "../src/storage/game/";

class Provider
{
public:
    Provider(GameState& state, SaveReader& saveReader):
            state(state), saveReader(saveReader)
    {}

    virtual void load() = 0;

protected:
    GameState& state;
    SaveReader& saveReader;
};

#endif //SFMLDEMO_PROVIDER_H
