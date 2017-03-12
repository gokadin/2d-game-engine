#include "AnimationDispatcher.h"
#include "character/CharacterAnimations.h"
#include "skills/SkillAnimations.h"

AnimationDispatcher::AnimationDispatcher(GameState &state)
{
    managers[animation_groups::CHARACTER] = new CharacterAnimations(state);
    managers[animation_groups::SKILLS] = new SkillAnimations(state);
}

AnimationDispatcher::~AnimationDispatcher()
{
    for (std::pair<animation_groups , AnimationManager *> pair : managers)
    {
        pair.second = NULL;
        delete pair.second;
    }
    managers.clear();
}

void AnimationDispatcher::update()
{
    for (std::pair<animation_groups , AnimationManager *> pair : managers)
    {
        pair.second->update();
    }
}
