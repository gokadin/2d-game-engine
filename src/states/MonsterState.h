#ifndef SFMLDEMO_MONSTERSTATE_H
#define SFMLDEMO_MONSTERSTATE_H

#include "../data/providers/monsters/MonsterTypes.h"

struct MonsterState
{
    std::string texture;
    monster_types type;
    int spriteWidth;
    int spriteHeight;
    int spriteOffsetX;
    int spriteOffsetY;
    int boxWidth;
    int boxHeight;
    int legRoom;
    int x;
    int y;
};

#endif //SFMLDEMO_MONSTERSTATE_H
