#include "Skill.h"
#include "../core/Engine.h"

Skill::Skill(int castTime, int castAnimationTime, bool isProjectile):
        m_castTime(castTime), m_castAnimationTime(castAnimationTime), m_isActive(false), m_isProjectile(isProjectile), 
        m_isCastingAnimationFinished(true), m_castAnimationTimeCounter(0),
        m_castAnimationUpdates(castAnimationTime * Engine::UPS / 1000)
{}

void Skill::countCastAnimationTime()
{
    m_castAnimationTimeCounter++;
    if (m_castAnimationTimeCounter == m_castAnimationUpdates)
    {
        m_isCastingAnimationFinished = true;
        m_castAnimationTimeCounter = 0;
    }
}
