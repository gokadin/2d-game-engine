#include "InstantCastAnimation.h"
#include "../../../core/Engine.h"

InstantCastAnimation::InstantCastAnimation(CharacterGraphics *graphics, CharacterState *state):
        Animation(false), m_graphics(graphics), m_state(state)
{}

void InstantCastAnimation::update()
{
    m_counter++;
    if (m_counter == animationFrames)
    {
        stop();
        return;
    }

    if (m_counter % stageFrames == 0)
    {
        m_stage++;
        updateSprite();
    }
}

void InstantCastAnimation::updateSprite()
{
    m_graphics->setSpriteOffsetY(SPRITE_POS_Y * m_graphics->spriteHeight());
    m_graphics->setSpriteOffsetX(m_stage * m_graphics->spriteWidth());
}

void InstantCastAnimation::start(Skill &skill)
{
    m_isActive = true;
    m_counter = 0;
    m_stage = 0;
    animationFrames = Engine::UPS * skill.castAnimationTime() / 1000;
    stageFrames = animationFrames / NUM_STAGES;
    updateSprite();
}

void InstantCastAnimation::stop()
{
    m_isActive = false;
}