#ifndef SFMLDEMO_OBJECTIVECOMPLETED_H
#define SFMLDEMO_OBJECTIVECOMPLETED_H

#include "../../utils/observable/Event.h"

class ObjectiveCompletedEvent : public Event
{
public:
    ObjectiveCompletedEvent()
            : Event(event_type::OBJECTIVE_COMPLETED)
    {}
};

#endif //SFMLDEMO_OBJECTIVECOMPLETED_H
