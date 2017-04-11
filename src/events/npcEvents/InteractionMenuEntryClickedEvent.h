#ifndef SFMLDEMO_INTERACTIONMENUENTRYCLICKEDEVENT_H
#define SFMLDEMO_INTERACTIONMENUENTRYCLICKEDEVENT_H

#include "../../utils/Event.h"

class InteractionMenuEntryClickedEvent : public Event
{
public:
    InteractionMenuEntryClickedEvent(int id)
            : Event(event_type::INTERACTION_MENU_ENTRY_CLICKED),
              m_id(id)
    {}

    inline int id() { return m_id; }

private:
    int m_id;
};

#endif //SFMLDEMO_INTERACTIONMENUENTRYCLICKEDEVENT_H
