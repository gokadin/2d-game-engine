#ifndef SFMLDEMO_WALKINGANIMATION_H
#define SFMLDEMO_WALKINGANIMATION_H

#include "../../Animation.h"
#include "../../../data/definitions/character/CharacterGraphics.h"
#include "../../../data/definitions/character/CharacterState.h"

class WalkAnimation : public Animation
{
public:
    WalkAnimation(CharacterGraphics *graphics, CharacterState *state);

    void update();
    void stop();
    void start();

private:
    const int APS = 6;
    const int SPRITE_POS_Y = 1;
    const int NUM_STAGES = 2;

    CharacterGraphics *m_graphics;
    CharacterState *m_state;

    void updateSprite();
};

#endif //SFMLDEMO_WALKINGANIMATION_H
