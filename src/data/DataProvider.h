#ifndef SFMLDEMO_DATAPROVIDERS_H
#define SFMLDEMO_DATAPROVIDERS_H

#include <vector>
#include "../states/GameState.h"

class DataProvider
{
public:
    DataProvider(GameState *state)
    {
        state->map.x = 960;
        state->map.y = 540;

        state->character.isMovingUp = false;
        state->character.isMovingDown = false;
        state->character.isMovingRight = false;
        state->character.isMovingLeft = false;

//        for (int i = 0; i < state->config.width; i++)
//        {
//            std::vector<int> line;
//            for (int j = 0; j < state->config.height; i++)
//            {
//                line.push_back(0);
//            }
//
//            state->map.bounds.push_back(line);
//        }
    }
};

#endif //SFMLDEMO_DATAPROVIDERS_H
