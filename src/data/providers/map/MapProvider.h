#ifndef SFMLDEMO_MAPPROVIDER_H
#define SFMLDEMO_MAPPROVIDER_H

#include "../Provider.h"

class MapProvider : public Provider
{
public:
    MapProvider(GameState& state, SaveReader& saveReader);

    void load();
};

#endif //SFMLDEMO_MAPPROVIDER_H
