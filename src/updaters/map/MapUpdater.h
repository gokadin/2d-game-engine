#ifndef SFMLDEMO_MAPUPDATER_H
#define SFMLDEMO_MAPUPDATER_H

#include "../Updater.h"

class MapUpdater : public Updater
{
public:
    MapUpdater(GameState *state);

    void update();
};

#endif //SFMLDEMO_MAPUPDATER_H
