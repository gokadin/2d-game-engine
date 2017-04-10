#ifndef SFMLDEMO_QUESTACCEPTEDEVENT_H
#define SFMLDEMO_QUESTACCEPTEDEVENT_H

#include "../../utils/Event.h"
#include "../../enums/quests/QuestName.h"

class QuestAcceptedEvent : public Event
{
public:
    QuestAcceptedEvent(event_type type, quest_name questName)
            : Event(type), m_questName(questName)
    {}

    inline quest_name questName() { return m_questName; }

private:
    quest_name m_questName;
};

#endif //SFMLDEMO_QUESTACCEPTEDEVENT_H
