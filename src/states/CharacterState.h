#ifndef SFMLDEMO_CHARACTERSTATE_H
#define SFMLDEMO_CHARACTERSTATE_H

struct CharacterState
{
    bool isMovingUp;
    bool isMovingDown;
    bool isMovingRight;
    bool isMovingLeft;
    int x;
    int y;
    int boxWidth;
    int boxHeight;
};

#endif //SFMLDEMO_CHARACTERSTATE_H
