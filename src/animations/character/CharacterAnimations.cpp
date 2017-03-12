#include "CharacterAnimations.h"
#include "movement/WalkAnimation.h"
#include "movement/StandAnimation.h"

CharacterAnimations::CharacterAnimations(GameState &state):
        AnimationManager(state)
{
    animations[animation_types::CHARACTER_STAND] = new StandAnimation(state);
    animations[animation_types::CHARACTER_WALK] = new WalkAnimation(state);
}
