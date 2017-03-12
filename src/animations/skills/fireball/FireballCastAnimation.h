#ifndef SFMLDEMO_FIREBALLCASTANIMATION_H
#define SFMLDEMO_FIREBALLCASTANIMATION_H

#include "../../Animation.h"

class FireballCastAnimation : public Animation
{
public:
    FireballCastAnimation(GameState &state);

    void update();
};

#endif //SFMLDEMO_FIREBALLCASTANIMATION_H
