#ifndef SFMLDEMO_READSAVE_H
#define SFMLDEMO_READSAVE_H

#include "../../states/GameState.h"

const std::string SAVE_ROOT = "../src/storage/save/";
const std::string POSITION = SAVE_ROOT + "position";

class SaveReader
{
public:
    SaveReader(GameState& state);

    void read();

private:
    GameState& state;
};

#endif //SFMLDEMO_READSAVE_H
