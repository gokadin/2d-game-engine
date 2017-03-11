#ifndef SFMLDEMO_CHARACTERPROVIDER_H
#define SFMLDEMO_CHARACTERPROVIDER_H

#include "../Provider.h"

class CharacterProvider : public Provider
{
public:
    CharacterProvider(GameState &state, SaveReader &saveReader);

    void load();
};

#endif //SFMLDEMO_CHARACTERPROVIDER_H
