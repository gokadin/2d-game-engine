#ifndef SFMLDEMO_CHARACTERSTATS_H
#define SFMLDEMO_CHARACTERSTATS_H

#include "../Stats.h"

class CharacterStats : public Stats
{
public:
    CharacterStats():
            m_life(100), m_moveModifier(1.0f)
    {}

    inline int life() { return m_life; }
    inline float moveSpeed() { return BASE_MOVE_SPEED * m_moveModifier; }

    inline void setMoveModifier(float moveModifier) { m_moveModifier = moveModifier; }

private:
    const int BASE_MOVE_SPEED = 2;

    int m_life;
    float m_moveModifier;
};

#endif //SFMLDEMO_CHARACTERSTATS_H
