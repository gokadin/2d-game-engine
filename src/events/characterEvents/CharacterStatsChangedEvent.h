#ifndef SFMLDEMO_CHARACTERSTATSCHANGEDEVENT_H
#define SFMLDEMO_CHARACTERSTATSCHANGEDEVENT_H

#include "../../utils/Event.h"

class CharacterStatsChanged : public Event
{
public:
    CharacterStatsChanged(event_type type):
            Event(type)
    {}
};

#endif //SFMLDEMO_CHARACTERSTATSCHANGEDEVENT_H
