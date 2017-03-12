#include "AnimationDispatcher.h"
#include "character/CharacterAnimations.h"

AnimationDispatcher::AnimationDispatcher(GameState &state)
{
    managers[animation_groups::CHARACTER] = new CharacterAnimations(state);
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
