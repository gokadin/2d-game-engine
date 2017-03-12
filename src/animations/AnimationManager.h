#ifndef SFMLDEMO_ANIMATIONMANAGER_H
#define SFMLDEMO_ANIMATIONMANAGER_H

#include <iostream>
#include <map>
#include "Animation.h"
#include "../states/GameState.h"
#include "AnimationTypes.h"

class AnimationManager
{
public:
    AnimationManager(GameState& state);
    virtual ~AnimationManager();

    virtual void update();

protected:
    GameState& state;
    std::map<animation_types , Animation *> animations;
};

#endif //SFMLDEMO_ANIMATIONMANAGER_H
