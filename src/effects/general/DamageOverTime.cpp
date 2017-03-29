#include "DamageOverTime.h"
#include "../../core/Engine.h"

DamageOverTime::DamageOverTime(MortalEntity *mortal, int damage, int durationMs):
        m_mortal(mortal), m_totalDamage(damage), m_damageDone(0.0f), m_damageBuffer(0.0f)
{
    m_frames = durationMs * Engine::UPS / 1000;
    m_damagePerFrame = (float)damage / m_frames;
}

void DamageOverTime::update()
{
    m_damageDone += m_damagePerFrame;
    m_damageBuffer += m_damagePerFrame;
    if (m_damageBuffer >= 1)
    {
        m_mortal->inflictDamage((int)floorf(m_damageBuffer));
        m_damageBuffer -= floorf(m_damageBuffer);
    }

    if (m_damageDone >= m_totalDamage)
    {
        m_isCompleted = true;
    }
}
