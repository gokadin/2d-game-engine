#include "AnimationManager.h"

AnimationManager::AnimationManager(GameState& state):
        state(state)
{}

AnimationManager::~AnimationManager()
{
    for (std::pair<animation_types, Animation *> pair : animations)
    {
        pair.second = NULL;
        delete pair.second;
    }
    animations.clear();
}

void AnimationManager::update()
{
    for (std::pair<animation_types , Animation *> pair : animations)
    {
        pair.second->update();
    }
}
