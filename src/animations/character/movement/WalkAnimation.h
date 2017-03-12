#ifndef SFMLDEMO_WALKINGANIMATION_H
#define SFMLDEMO_WALKINGANIMATION_H

#include "../../Animation.h"

class WalkAnimation : public Animation
{
public:
    WalkAnimation(GameState &state);

    void update();

private:
    const int APS = 6;
    const int SPRITE_POS_Y = 1;
    const int NUM_STAGES = 2;

    void animate();
    void updateSprite();
};

#endif //SFMLDEMO_WALKINGANIMATION_H
