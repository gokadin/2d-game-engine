#ifndef SFMLDEMO_CHARACTERSTATSCHANGEDEVENT_H
#define SFMLDEMO_CHARACTERSTATSCHANGEDEVENT_H

#include "../../utils/observable/Event.h"

class CharacterStatsChanged : public Event
{
public:
    CharacterStatsChanged():
            Event(event_type::CHARACTER_STATS_CHANGED)
    {}
};

#endif //SFMLDEMO_CHARACTERSTATSCHANGEDEVENT_H
