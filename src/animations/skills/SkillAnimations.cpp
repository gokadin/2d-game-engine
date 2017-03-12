#include "SkillAnimations.h"
#include "fireball/FireballFlyAnimation.h"

SkillAnimations::SkillAnimations(GameState &state):
        AnimationManager(state)
{
    animations[animation_types::SKILL_FIREBALL_FLY] = new FireballFlyAnimation(state);
}
