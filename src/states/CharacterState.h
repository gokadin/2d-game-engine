#ifndef SFMLDEMO_CHARACTERSTATE_H
#define SFMLDEMO_CHARACTERSTATE_H

struct CharacterState
{
    std::string texture;
    int spriteWidth;
    int spriteHeight;
    int spriteOffsetX;
    int spriteOffsetY;
    bool isMovingUp;
    bool isMovingDown;
    bool isMovingRight;
    bool isMovingLeft;
    int boxWidth;
    int boxHeight;
    int legRoom;
    int moveSpeed;

    bool isMoving()
    {
        return isMovingUp || isMovingDown || isMovingRight || isMovingLeft;
    }

    bool isIdle()
    {
        return !isMoving();
    }
};

#endif //SFMLDEMO_CHARACTERSTATE_H
