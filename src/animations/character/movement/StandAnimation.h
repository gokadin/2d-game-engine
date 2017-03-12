#ifndef SFMLDEMO_STANDINGANIMATION_H
#define SFMLDEMO_STANDINGANIMATION_H

#include "../../Animation.h"

class StandAnimation : public Animation
{
public:
    StandAnimation(GameState &state);

    void update();

private:
    const int APS = 6;
    const int SPRITE_POS_Y = 0;
    const int NUM_STAGES = 1;

    void animate();
    void updateSprite();
};

#endif //SFMLDEMO_STANDINGANIMATION_H
