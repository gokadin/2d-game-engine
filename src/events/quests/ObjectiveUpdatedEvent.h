#ifndef SFMLDEMO_OBJECTIVEUPDATEDEVENT_H
#define SFMLDEMO_OBJECTIVEUPDATEDEVENT_H

#include "../../utils/observable/Event.h"

class ObjectiveUpdatedEvent : public Event
{
public:
    ObjectiveUpdatedEvent()
            : Event(event_type::OBJECTIVE_UPDATED)
    {}

private:

};

#endif //SFMLDEMO_OBJECTIVEUPDATEDEVENT_H
