#ifndef SFMLDEMO_MONSTERPROVIDER_H
#define SFMLDEMO_MONSTERPROVIDER_H

#include "../Provider.h"

class MonsterProvider : public Provider
{
public:
    MonsterProvider(GameState &state, SaveReader &saveReader);

    void load();
};

#endif //SFMLDEMO_MONSTERPROVIDER_H
