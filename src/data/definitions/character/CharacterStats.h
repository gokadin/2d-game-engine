#ifndef SFMLDEMO_CHARACTERSTATS_H
#define SFMLDEMO_CHARACTERSTATS_H

#include "../Stats.h"
#include "../../../utils/Observable.h"
#include "../../../events/characterEvents/CharacterStatsChangedEvent.h"

class CharacterStats : public Stats, public Observable
{
public:
    CharacterStats():
            m_moveModifier(1.0f)
    {}

    inline float moveSpeed() { return BASE_MOVE_SPEED * m_moveModifier; }
    inline int spellPower() { return m_spellPower; }

    inline void setMoveModifier(float moveModifier) { m_moveModifier = moveModifier; }

    inline void addSpellPower(int spellPower)
    {
        m_spellPower += spellPower;
        notifyObservers(new CharacterStatsChanged(event_type::CHARACTER_STATS_CHANGED));
    }
    inline void removeSpellPower(int spellPower)
    {
        m_spellPower -= spellPower;
        notifyObservers(new CharacterStatsChanged(event_type::CHARACTER_STATS_CHANGED));
    }

private:
    const int BASE_MOVE_SPEED = 2;

    float m_moveModifier;
    int m_spellPower;
};

#endif //SFMLDEMO_CHARACTERSTATS_H
