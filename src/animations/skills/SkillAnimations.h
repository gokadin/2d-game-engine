#ifndef SFMLDEMO_SKILLANIMATIONS_H
#define SFMLDEMO_SKILLANIMATIONS_H

#include "../AnimationManager.h"

class SkillAnimations : public AnimationManager
{
public:
    SkillAnimations(GameState &state);

    void update();
};

#endif //SFMLDEMO_SKILLANIMATIONS_H