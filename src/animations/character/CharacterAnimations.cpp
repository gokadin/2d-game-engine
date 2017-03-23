#include "CharacterAnimations.h"
#include "skillCasts/InstantCastAnimation.h"
#include "movement/WalkAnimation.h"
#include "movement/StandAnimation.h"

CharacterAnimations::CharacterAnimations(CharacterState *state, CharacterGraphics *graphics,
                                         EquipmentManager *equipmentManager):
        m_state(state), m_graphics(graphics), m_equipmentManager(equipmentManager)
{
    m_animations[character_animation_type::INSTANT_CAST] = new InstantCastAnimation(graphics, state);
    m_animations[character_animation_type::MOVE] = new WalkAnimation(graphics, state, equipmentManager);
    m_animations[character_animation_type::IDLE] = new StandAnimation(graphics, state);
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
