#ifndef SFMLDEMO_EVENT_H
#define SFMLDEMO_EVENT_H

#include "../../enums/EventType.h"

class Event
{
public:
    Event(event_type type):
            m_type(type)
    {}

    inline event_type type() { return m_type; }

private:
    event_type m_type;
};

#endif //SFMLDEMO_EVENT_H
