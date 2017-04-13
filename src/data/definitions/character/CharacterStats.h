#ifndef SFMLDEMO_CHARACTERSTATS_H
#define SFMLDEMO_CHARACTERSTATS_H

#include "../Stats.h"
#include "../../../utils/Observable.h"
#include "../../../events/characterEvents/CharacterStatsChangedEvent.h"
#include "../../../monsters/Monster.h"
#include "../../../events/characterEvents/CharacterExperienceGainedEvent.h"
#include "../../../events/characterEvents/CharacterLevelGainedEvent.h"

class CharacterStats : public Stats, public Observable
{
public:
    CharacterStats()
            : m_moveModifier(1.0f),
              m_spellPower(0),
              m_experience(0),
              m_level(1)
    {}

    inline float moveSpeed() { return BASE_MOVE_SPEED * m_moveModifier; }
    inline int spellPower() { return m_spellPower; }

    inline void setMoveModifier(float moveModifier) { m_moveModifier = moveModifier; }

    inline void addSpellPower(int spellPower)
    {
        m_spellPower += spellPower;
        notifyObservers(std::make_shared<CharacterStatsChanged>());
    }

    inline void removeSpellPower(int spellPower)
    {
        m_spellPower -= spellPower;
        notifyObservers(std::make_shared<CharacterStatsChanged>());
    }

    void handleMonsterDied(Monster *monster)
    {
        m_experience += 100;
        notifyObservers(std::make_shared<CharacterExperienceGainedEvent>());
    }

private:
    const int BASE_MOVE_SPEED = 2;

    float m_moveModifier;
    int m_spellPower;
    int m_experience;
    int m_level;

    void levelUp()
    {
        m_level++;
        notifyObservers(std::make_shared<CharacterLevelGainedEvent>());
    }
};

#endif //SFMLDEMO_CHARACTERSTATS_H
