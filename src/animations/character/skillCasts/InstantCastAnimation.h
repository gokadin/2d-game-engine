#ifndef SFMLDEMO_INSTANTCASTANIMATION_H
#define SFMLDEMO_INSTANTCASTANIMATION_H

#include "../../Animation.h"
#include "../../../data/definitions/character/CharacterGraphics.h"
#include "../../../skills/Skill.h"
#include "../../../data/definitions/character/CharacterState.h"
#include "../../../utils/observable/Observable.h"

class InstantCastAnimation : public Animation, public Observable
{
public:
    InstantCastAnimation(CharacterGraphics *graphics, CharacterState *state);

    void update();
    void stop();
    void start(Skill &skill);

private:
    const int SPRITE_POS_Y = 2;
    const int NUM_STAGES = 6;

    CharacterState *m_state;
    CharacterGraphics *m_graphics;
    int animationFrames;
    int stageFrames;

    void updateSprite();
};

#endif //SFMLDEMO_INSTANTCASTANIMATION_H
