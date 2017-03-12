#include "SkillAnimations.h"
#include "fireball/FireballFlyAnimation.h"

SkillAnimations::SkillAnimations(GameState &state):
        AnimationManager(state)
{
    animations[animation_types::SKILL_FIREBALL_FLY] = new FireballFlyAnimation(state);
}

void SkillAnimations::update()
{
    if (state.character.skills[0].isActive)
    {
        //animations[state.character.skills[state.character.castingSkillIndex].name]->update();
    }
}
