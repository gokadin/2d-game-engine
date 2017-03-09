#ifndef SFMLDEMO_EVENT_H
#define SFMLDEMO_EVENT_H

#include <string>
#include "../core/eventTypes.h"

class Event
{
public:
    Event(event_type type)
    {
        this->type = type;
    }

    virtual ~Event() {}

    inline event_type getType() { return type; }

private:
    event_type type;
};

#endif //SFMLDEMO_EVENT_H
