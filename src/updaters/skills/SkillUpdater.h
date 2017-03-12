#ifndef SFMLDEMO_SKILLUPDATER_H
#define SFMLDEMO_SKILLUPDATER_H

#include "../Updater.h"

class SkillUpdater : public Updater
{
public:
    SkillUpdater(GameState &state);

    void update();
};

#endif //SFMLDEMO_SKILLUPDATER_H
