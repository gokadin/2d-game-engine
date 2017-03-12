#ifndef SFMLDEMO_FIREBALLFLYANIMATION_H
#define SFMLDEMO_FIREBALLFLYANIMATION_H

#include "../../Animation.h"

class FireballFlyAnimation : public Animation
{
public:
    FireballFlyAnimation(GameState &state);

    void update();
};

#endif //SFMLDEMO_FIREBALLFLYANIMATION_H
