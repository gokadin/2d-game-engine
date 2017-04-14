#include "CharacterStats.h"

CharacterStats::CharacterStats()
        : m_moveModifier(1.0f),
          m_spellPower(0),
          m_currentExperience(0),
          m_levelExperience(0),
          m_previousLevelExperience(0),
          m_level(0)
{
    // temp
    levelUp();
}

void CharacterStats::addSpellPower(int spellPower)
{
    m_spellPower += spellPower;
    notifyParent(std::make_shared<CharacterStatsChanged>());
}

void CharacterStats::removeSpellPower(int spellPower)
{
    m_spellPower -= spellPower;
    notifyParent(std::make_shared<CharacterStatsChanged>());
}

void CharacterStats::handleMonsterDied(Monster *monster)
{
    m_currentExperience += monster->experienceWorth();
    if (m_currentExperience >= m_levelExperience)
    {
        levelUp();
    }

    notifyParent(std::make_shared<CharacterExperienceGainedEvent>(m_levelExperience, m_previousLevelExperience,
                                                                  m_currentExperience));
}

void CharacterStats::levelUp()
{
    m_level++;
    m_previousLevelExperience = m_levelExperience;
    m_levelExperience = (uint32_t)(BASE_EXPERIENCE * m_level * m_level);

    notifyParent(std::make_shared<CharacterLevelGainedEvent>());
}
