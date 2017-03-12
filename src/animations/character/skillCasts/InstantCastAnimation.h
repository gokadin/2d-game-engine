#ifndef SFMLDEMO_INSTANTCASTANIMATION_H
#define SFMLDEMO_INSTANTCASTANIMATION_H

#include "../../Animation.h"

class InstantCastAnimation : public Animation
{
public:
    InstantCastAnimation(GameState &state);

    void update();

protected:
    const int SPRITE_POS_Y = 2;
    const int NUM_STAGES = 6;

    int animationFrames;
    int stageFrames;

    void animate();
    void updateSprite();
};

#endif //SFMLDEMO_INSTANTCASTANIMATION_H
