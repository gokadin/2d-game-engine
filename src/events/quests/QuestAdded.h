#ifndef SFMLDEMO_QUESTADDED_H
#define SFMLDEMO_QUESTADDED_H

#include "../../utils/Event.h"
#include "../../components/quests/Quest.h"

class QuestAddedEvent : public Event
{
public:
    QuestAddedEvent(Quest *quest)
            : Event(event_type::QUEST_ADDED),
              m_quest(quest)
    {}

    inline Quest *quest() { return m_quest; }

private:
    Quest *m_quest;
};

#endif //SFMLDEMO_QUESTADDED_H
