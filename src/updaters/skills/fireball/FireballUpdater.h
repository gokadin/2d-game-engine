#ifndef SFMLDEMO_FIREBALLUPDATER_H
#define SFMLDEMO_FIREBALLUPDATER_H

#include "../SkillUpdater.h"

class FireballUpdater : public SkillUpdater
{
public:
    FireballUpdater(GameState &state);

    void update();
};

#endif //SFMLDEMO_FIREBALLUPDATER_H
