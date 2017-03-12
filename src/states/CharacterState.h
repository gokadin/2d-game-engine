#ifndef SFMLDEMO_CHARACTERSTATE_H
#define SFMLDEMO_CHARACTERSTATE_H

#include "SkillState.h"
#include "../enums/CastingTypes.h"

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
    bool pauseMovement;
    int boxWidth;
    int boxHeight;
    int legRoom;
    int moveSpeed;
    std::vector<SkillState> skills;
    bool isCasting;
    casting_types castingType;
    int castingSkillIndex;

    bool isMoving()
    {
        return !pauseMovement && (isMovingUp || isMovingDown || isMovingRight || isMovingLeft);
    }

    bool isIdle()
    {
        return !isMoving() && !isCasting;
    }
};

#endif //SFMLDEMO_CHARACTERSTATE_H
