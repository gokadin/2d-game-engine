#ifndef SFMLDEMO_STANDINGANIMATION_H
#define SFMLDEMO_STANDINGANIMATION_H

#include "../../Animation.h"
#include "../../../data/definitions/character/CharacterState.h"
#include "../../../data/definitions/character/CharacterGraphics.h"

class StandAnimation : public Animation
{
public:
    StandAnimation(CharacterGraphics *graphics, CharacterState *state);

    void update();
    void stop();
    void start();

private:
    const int APS = 6;
    const int SPRITE_POS_Y = 0;
    const int NUM_STAGES = 1;

    CharacterGraphics *m_graphics;
    CharacterState *m_state;

    void updateSprite();
};

#endif //SFMLDEMO_STANDINGANIMATION_H
