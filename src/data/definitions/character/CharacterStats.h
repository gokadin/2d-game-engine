#ifndef SFMLDEMO_CHARACTERSTATS_H
#define SFMLDEMO_CHARACTERSTATS_H

#include "../Stats.h"
#include "../../../events/characterEvents/CharacterStatsChangedEvent.h"
#include "../../../monsters/Monster.h"
#include "../../../events/characterEvents/CharacterExperienceGainedEvent.h"
#include "../../../events/characterEvents/CharacterLevelGainedEvent.h"
#include "../../../utils/observable/ObservableChild.h"

class CharacterStats : public Stats, public ObservableChild
{
public:
    CharacterStats();

    inline float moveSpeed() { return BASE_MOVE_SPEED * m_moveModifier; }
    inline int spellPower() { return m_spellPower; }

    void addSpellPower(int spellPower);
    void removeSpellPower(int spellPower);
    void handleMonsterDied(Monster *monster);

private:
    const int BASE_MOVE_SPEED = 2;
    const int BASE_EXPERIENCE = 1000;

    float m_moveModifier;
    int m_spellPower;
    uint32_t m_currentExperience;
    uint32_t m_levelExperience;
    uint32_t m_previousLevelExperience;
    uint8_t m_level;

    void levelUp();
};

#endif //SFMLDEMO_CHARACTERSTATS_H
