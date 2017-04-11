#ifndef SFMLDEMO_ACTIVEQUESTCHANGED_H
#define SFMLDEMO_ACTIVEQUESTCHANGED_H

#include "../../utils/Event.h"
#include "../../components/quests/Quest.h"

class ActiveQuestChangedEvent : public Event
{
public:
    ActiveQuestChangedEvent(Quest *activeQuest)
            : Event(event_type::ACTIVE_QUEST_CHANGED), m_activeQuest(activeQuest)
    {}

    inline Quest *activeQuest() { return m_activeQuest; }

private:
    Quest *m_activeQuest;
};

#endif //SFMLDEMO_ACTIVEQUESTCHANGED_H
