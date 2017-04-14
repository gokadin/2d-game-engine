#ifndef SFMLDEMO_INTERACTIONCANCELLEDEVENT_H
#define SFMLDEMO_INTERACTIONCANCELLEDEVENT_H

#include "../../utils/observable/Event.h"

class InteractionCancelledEvent : public Event
{
public:
    InteractionCancelledEvent()
            : Event(event_type::INTERACTION_CANCELLED)
    {}
};

#endif //SFMLDEMO_INTERACTIONCANCELLEDEVENT_H
