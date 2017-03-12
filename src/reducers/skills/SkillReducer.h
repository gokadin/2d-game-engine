#ifndef SFMLDEMO_SKILLREDUCER_H
#define SFMLDEMO_SKILLREDUCER_H

#include "../../states/GameState.h"
#include "../../actions/ActionTypes.h"

class SkillReducer
{
public:
    SkillReducer(GameState &state);

    virtual void process(int stateIndex, int targetX, int targetY) = 0;

protected:
    GameState& state;
};

#endif //SFMLDEMO_SKILLREDUCER_H
