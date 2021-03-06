#include "StandAnimation.h"

StandAnimation::StandAnimation(CharacterGraphics *graphics, CharacterState *state):
        Animation(true), m_graphics(graphics), m_state(state)
{}

void StandAnimation::update()
{
    if (!m_state->isIdle())
    {
        return;
    }

    m_counter++;
    if (m_counter < Engine::UPS / APS)
    {
        return;
    }

    m_counter = 0;

    m_stage++;
    if (m_stage == NUM_STAGES)
    {
        m_stage = 0;
    }

    updateSprite();
}

void StandAnimation::updateSprite()
{
    m_graphics->setSpriteOffsetY(SPRITE_POS_Y * m_graphics->spriteHeight());
    m_graphics->setSpriteOffsetX(m_stage * m_graphics->spriteWidth());
}

void StandAnimation::stop()
{

}

void StandAnimation::start()
{

}
