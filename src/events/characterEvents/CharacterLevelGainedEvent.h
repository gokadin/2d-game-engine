#ifndef SFMLDEMO_CHARACTERLEVELGAINEDEVENT_H
#define SFMLDEMO_CHARACTERLEVELGAINEDEVENT_H

#include "../../utils/Event.h"

class CharacterLevelGainedEvent : public Event
{
public:
    CharacterLevelGainedEvent()
            : Event(event_type::CHARACTER_LEVEL_GAINED) {}
};

#endif //SFMLDEMO_CHARACTERLEVELGAINEDEVENT_H
