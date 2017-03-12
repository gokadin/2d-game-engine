#ifndef SFMLDEMO_ANIMATIONDISPATCHER_H
#define SFMLDEMO_ANIMATIONDISPATCHER_H

#include <map>
#include "AnimationManager.h"
#include "AnimationGroups.h"

class AnimationDispatcher
{
public:
    AnimationDispatcher(GameState& state);
    ~AnimationDispatcher();

    void update();

private:
    std::map<animation_groups , AnimationManager *> managers;
};

#endif //SFMLDEMO_ANIMATIONDISPATCHER_H
