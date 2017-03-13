//#include "StandAnimation.h"
//
//StandAnimation::StandAnimation(GameState &state):
//        Animation(state)
//{}
//
//void StandAnimation::update()
//{
//    if (!state.character.isIdle())
//    {
//        if (isActive)
//        {
//            isActive = false;
//        }
//
//        return;
//    }
//
//    if (!isActive)
//    {
//        isActive = true;
//        counter = 0;
//        stage = 0;
//        updateSprite();
//    }
//
//    animate();
//}
//
//void StandAnimation::animate()
//{
//    counter++;
//    if (counter < state.config.ups / APS)
//    {
//        return;
//    }
//
//    counter = 0;
//
//    stage++;
//    if (stage == NUM_STAGES)
//    {
//        stage = 0;
//    }
//
//    updateSprite();
//}
//
//void StandAnimation::updateSprite()
//{
//    state.character.spriteOffsetY = SPRITE_POS_Y * state.character.spriteHeight;
//    state.character.spriteOffsetX = stage * state.character.spriteWidth;
//}
