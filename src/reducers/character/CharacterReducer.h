#ifndef SFMLDEMO_CHARACTERREDUCER_H
#define SFMLDEMO_CHARACTERREDUCER_H

#include "../Reducer.h"
#include "../../actions/ActionTypes.h"

class CharacterReducer : public Reducer
{
public:
    CharacterReducer(GameState &state);

    void process(action_types type);
};

#endif //SFMLDEMO_CHARACTERREDUCER_H
