#ifndef SFMLDEMO_CHARACTERSTATE_H
#define SFMLDEMO_CHARACTERSTATE_H

struct CharacterState
{
    std::string texture;
    bool isMovingUp;
    bool isMovingDown;
    bool isMovingRight;
    bool isMovingLeft;
    int boxWidth;
    int boxHeight;
    int legRoom;
    int moveSpeed;
};

#endif //SFMLDEMO_CHARACTERSTATE_H
