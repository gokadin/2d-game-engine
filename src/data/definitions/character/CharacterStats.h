#ifndef SFMLDEMO_CHARACTERSTATS_H
#define SFMLDEMO_CHARACTERSTATS_H

#include "../Stats.h"

class CharacterStats : public Stats
{
public:
    CharacterStats():
            m_life(100)
    {}

    inline int life() { return m_life; }
    inline int moveSpeed() { return m_moveSpeed; }

private:
    int m_life;
    int m_moveSpeed;
};

#endif //SFMLDEMO_CHARACTERSTATS_H
