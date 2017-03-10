#ifndef SFMLDEMO_DATAPROVIDERS_H
#define SFMLDEMO_DATAPROVIDERS_H

#include <vector>
#include "../states/GameState.h"

class DataProvider
{
public:
    DataProvider(GameState *state, int screenWidth, int screenHeight)
    {
        state->config.width = screenWidth;
        state->config.height = screenHeight;

        state->map.x = screenWidth / 2;
        state->map.y = screenHeight / 2;

        state->character.isMovingUp = false;
        state->character.isMovingDown = false;
        state->character.isMovingRight = false;
        state->character.isMovingLeft = false;
        state->character.x = screenWidth / 2; // remove?
        state->character.y = screenHeight / 2; // remove?
        state->character.boxWidth = 10;
        state->character.boxHeight = 10;
        state->character.moveSpeed = 3;

        for (int i = 0; i < 1080; i++) // map height
        {
            std::vector<int> line;
            for (int j = 0; j < 1920; j++) // map width
            {
                if (i == 0 || i == 1 || i == 2 || i == 3 || i == 4 || i == 1075 || i == 1076 || i == 1077 || i == 1078 ||
                        i == 1079 || j == 0 || j == 1 || j == 2 || j == 3 || j == 4 || j == 1915 || j == 1916 || j == 1917 || j == 1918 || j == 1919)
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

        state->map.bounds[560][1010] = 1;
        state->map.bounds[560][1011] = 1;
        state->map.bounds[560][1012] = 1;
        state->map.bounds[560][1013] = 1;
        state->map.bounds[561][1010] = 1;
        state->map.bounds[561][1011] = 1;
        state->map.bounds[561][1012] = 1;
        state->map.bounds[561][1013] = 1;
        state->map.bounds[562][1010] = 1;
        state->map.bounds[562][1011] = 1;
        state->map.bounds[562][1012] = 1;
        state->map.bounds[562][1013] = 1;
        state->map.bounds[563][1010] = 1;
        state->map.bounds[563][1011] = 1;
        state->map.bounds[563][1012] = 1;
        state->map.bounds[563][1013] = 1;
    }
};

#endif //SFMLDEMO_DATAPROVIDERS_H
