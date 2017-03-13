#include "InstantCastAnimation.h"

InstantCastAnimation::InstantCastAnimation():
        Animation(false)
{}

void InstantCastAnimation::update()
{
//    if (!state.character.isCasting)
//    {
//        return;
//    }
//
//    if (!isActive)
//    {
//        isActive = true;
//        counter = 0;
//        stage = 0;
//        animationFrames = state.config.ups * state.character.skills[state.character.castingSkillIndex].castTimeMs / 1000;
//        stageFrames = animationFrames / NUM_STAGES;
//        updateSprite();
//    }
//
//    animate();
}

void InstantCastAnimation::animate()
{
//    counter++;
//    if (counter == animationFrames)
//    {
//        isActive = false;
//        state.character.isCasting = false;
//        state.character.pauseMovement = false;
//
//        return;
//    }
//
//    // update sprite NUM_STAGES times
//
//    if (counter % stageFrames == 0)
//    {
//        stage++;
//        updateSprite();
//    }
}

void InstantCastAnimation::updateSprite()
{
//    state.character.spriteOffsetY = SPRITE_POS_Y * state.character.spriteHeight;
//    state.character.spriteOffsetX = stage * state.character.spriteWidth;
}

void InstantCastAnimation::start()
{
    m_isActive = true;
    m_counter = 0;
    m_stage = 0;
}

void InstantCastAnimation::stop()
{
    m_isActive = false;
}

void InstantCastAnimation::reset()
{

}
