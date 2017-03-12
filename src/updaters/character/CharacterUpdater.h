#ifndef SFMLDEMO_CHARACTERUPDATER_H
#define SFMLDEMO_CHARACTERUPDATER_H

#include "../Updater.h"

class CharacterUpdater : public Updater
{
public:
    CharacterUpdater(GameState &state);

    void update();
};

#endif //SFMLDEMO_CHARACTERUPDATER_H
