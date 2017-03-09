#ifndef SFMLDEMO_DATAPROVIDERS_H
#define SFMLDEMO_DATAPROVIDERS_H

#include <vector>
#include "../states/GameState.h"

const int WIDTH = 1000;
const int HEIGHT = 1000;

class DataProvider
{
public:
    DataProvider(GameState *state, int screenWidth, int screenHeight)
    {
        state->config.width = WIDTH;
        state->config.height = HEIGHT;
        state->config.xScaleFactor = screenWidth / WIDTH;
        state->config.yScaleFactor = screenHeight / HEIGHT;

        state->map.x = 500;
        state->map.y = 500;

        state->character.isMovingUp = false;
        state->character.isMovingDown = false;
        state->character.isMovingRight = false;
        state->character.isMovingLeft = false;
        state->character.x = 500;
        state->character.y = 500;
        state->character.boxWidth = 10;
        state->character.boxHeight = 10;

        for (int i = 0; i < 1920; i++) // map height
        {
            std::vector<int> line;
            for (int j = 0; j < 1080; j++) // map width
            {
                if (i == 0 || i == 1919 || j == 0 || j == 1079)
                {
                    line.push_back(1);
                }
                else
                {
                    line.push_back(0); // fix all this
                }
            }

            state->map.bounds.push_back(line);
        }
    }
};

#endif //SFMLDEMO_DATAPROVIDERS_H
