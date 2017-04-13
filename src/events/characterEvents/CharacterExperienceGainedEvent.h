#ifndef SFMLDEMO_CHARACTEREXPERIENCEGAINEDEVENT_H
#define SFMLDEMO_CHARACTEREXPERIENCEGAINEDEVENT_H

#include "../../utils/Event.h"

class CharacterExperienceGainedEvent : public Event
{
public:
    CharacterExperienceGainedEvent()
            : Event(event_type::CHARACTER_EXPERIENCE_GAINED) {}
};

#endif //SFMLDEMO_CHARACTEREXPERIENCEGAINEDEVENT_H
