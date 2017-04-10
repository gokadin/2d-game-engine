#ifndef SFMLDEMO_INTERACTIONCANCELLEDEVENT_H
#define SFMLDEMO_INTERACTIONCANCELLEDEVENT_H

#include "../../utils/Event.h"

class InteractionCancelledEvent : public Event
{
public:
    InteractionCancelledEvent(event_type type) : Event(type)
    {}
};

#endif //SFMLDEMO_INTERACTIONCANCELLEDEVENT_H
