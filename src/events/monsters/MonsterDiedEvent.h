#ifndef SFMLDEMO_MONSTERDIEDEVENT_H
#define SFMLDEMO_MONSTERDIEDEVENT_H

#include "../../utils/observable/Event.h"
#include "../../monsters/Monster.h"

class MonsterDiedEvent : public Event
{
public:
    MonsterDiedEvent(Monster *monster)
            : Event(event_type::MONSTER_DIED),
              m_monster(monster)
    {}

    inline Monster* monster() { return m_monster; }

private:
    Monster *m_monster;
};

#endif //SFMLDEMO_MONSTERDIEDEVENT_H
