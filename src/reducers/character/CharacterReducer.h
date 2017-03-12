#ifndef SFMLDEMO_CHARACTERREDUCER_H
#define SFMLDEMO_CHARACTERREDUCER_H

#include "../Reducer.h"
#include "../../actions/ActionTypes.h"

class CharacterReducer : public Reducer
{
public:
    CharacterReducer(GameState &state);

    void process(action_types type, int x = 0, int y = 0);
};

#endif //SFMLDEMO_CHARACTERREDUCER_H
