#include "WalkAnimation.h"

WalkAnimation::WalkAnimation(GameState& state):
        Animation(state), stage(1)
{}

void WalkAnimation::update()
{
    if (!state.character.isMoving())
    {
        if (isActive)
        {
            isActive = false;
        }

        return;
    }

    if (!isActive)
    {
        isActive = true;
        counter = 0;
        stage = 0;
        updateSprite();
    }

    animate();
}

void WalkAnimation::animate()
{
    counter++;
    if (counter < state.config.ups / APS)
    {
        return;
    }

    counter = 0;

    stage++;
    if (stage == NUM_STAGES)
    {
        stage = 0;
    }

    updateSprite();
}

void WalkAnimation::updateSprite()
{
    state.character.spriteOffsetY = SPRITE_POS_Y * state.character.spriteHeight;
    state.character.spriteOffsetX = stage * state.character.spriteWidth;
}

