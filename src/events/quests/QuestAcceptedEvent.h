#ifndef SFMLDEMO_QUESTACCEPTEDEVENT_H
#define SFMLDEMO_QUESTACCEPTEDEVENT_H

#include "../../utils/observable/Event.h"
#include "../../enums/quests/QuestName.h"

class QuestAcceptedEvent : public Event
{
public:
    QuestAcceptedEvent(quest_name questName)
            : Event(event_type::QUEST_ACCEPTED), m_questName(questName)
    {}

    inline quest_name questName() { return m_questName; }

private:
    quest_name m_questName;
};

#endif //SFMLDEMO_QUESTACCEPTEDEVENT_H
