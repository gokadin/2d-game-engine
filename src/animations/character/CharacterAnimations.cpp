#include "CharacterAnimations.h"
#include "skillCasts/InstantCastAnimation.h"

CharacterAnimations::CharacterAnimations(CharacterState *state, CharacterGraphics *graphics):
        m_state(state), m_graphics(graphics)
{
    m_animations[character_animation_type::CHARACTER_INSTANT_CAST] = new InstantCastAnimation(state, graphics);
}

CharacterAnimations::~CharacterAnimations()
{
    for (std::pair<character_animation_type, Animation *> pair : m_animations)
    {
        pair.second = NULL;
        delete pair.second;
    }
    m_animations.clear();
}

void CharacterAnimations::update()
{
    for (std::pair<character_animation_type, Animation *> pair : m_animations)
    {
        if (pair.second != NULL && pair.second->isActive())
        {
            pair.second->update();
        }
    }
}

Animation &CharacterAnimations::get(character_animation_type type)
{
    return *m_animations[type];
}
