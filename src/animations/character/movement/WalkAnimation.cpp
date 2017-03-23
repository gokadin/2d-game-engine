#include "WalkAnimation.h"

WalkAnimation::WalkAnimation(CharacterGraphics *graphics, CharacterState *state, EquipmentManager *equipmentManager):
        Animation(true), m_graphics(graphics), m_state(state), m_equipmentManager(equipmentManager)
{}

void WalkAnimation::update()
{
    if (!m_state->isMoving() || m_state->isMovementPaused())
    {
        m_stage = 0;
        return;
    }

    m_counter++;
    if (m_counter < Engine::UPS / APS)
    {
        return;
    }

    m_counter = 0;

    m_equipmentManager->setStage(m_stage);

    m_stage++;
    if (m_stage == NUM_STAGES)
    {
        m_stage = 0;
    }

    updateSprite();
}

void WalkAnimation::stop()
{

}

void WalkAnimation::start()
{

}

void WalkAnimation::updateSprite()
{
    m_graphics->setSpriteOffsetY(SPRITE_POS_Y * m_graphics->spriteHeight());
    m_graphics->setSpriteOffsetX(m_stage * m_graphics->spriteWidth());
}
