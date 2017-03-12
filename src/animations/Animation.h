#ifndef SFMLDEMO_ANIMATION_H
#define SFMLDEMO_ANIMATION_H

#include "../states/GameState.h"

class Animation
{
public:
    Animation(GameState& state);

    virtual void update() = 0;

protected:
    GameState& state;
    int counter;
    bool isActive;
    int stage;
};

#endif //SFMLDEMO_ANIMATION_H
