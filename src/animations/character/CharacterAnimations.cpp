#include "CharacterAnimations.h"
#include "skillCasts/InstantCastAnimation.h"

CharacterAnimations::CharacterAnimations()
{
    animations[character_animation_type::CHARACTER_INSTANT_CAST] = new InstantCastAnimation();
}

CharacterAnimations::~CharacterAnimations()
{
    for (std::pair<character_animation_type, Animation *> pair : animations)
    {
        pair.second = NULL;
        delete pair.second;
    }
    animations.clear();
}

void CharacterAnimations::update()
{
    for (std::pair<character_animation_type, Animation *> pair : animations)
    {
        if (pair.second != NULL && pair.second->isActive())
        {
            pair.second->update();
        }
    }
}

void CharacterAnimations::trigger(character_animation_type type)
{
    animations[type]->start();
}
