#ifndef SFMLDEMO_FIREBALLREDUCER_H
#define SFMLDEMO_FIREBALLREDUCER_H

#include "../SkillReducer.h"

class FireballReducer : public SkillReducer
{
public:
    FireballReducer(GameState &state);

    void process(int stateIndex, int targetX, int targetY);
};

#endif //SFMLDEMO_FIREBALLREDUCER_H
