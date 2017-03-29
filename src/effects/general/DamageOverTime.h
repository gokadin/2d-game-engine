#ifndef SFMLDEMO_DAMAGEOVERTIME_H
#define SFMLDEMO_DAMAGEOVERTIME_H

#include "../Effect.h"
#include "../../common/MortalEntity.h"

class DamageOverTime : public Effect
{
public:
    DamageOverTime(MortalEntity *mortal, int damage, int durationMs);

    void update();

private:
    MortalEntity *m_mortal;
    int m_totalDamage;
    float m_damageDone;
    float m_damagePerFrame;
    float m_damageBuffer;
};

#endif //SFMLDEMO_DAMAGEOVERTIME_H
