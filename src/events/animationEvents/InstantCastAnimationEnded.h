#ifndef SFMLDEMO_INSTANTCASTANIMATIONENDED_H
#define SFMLDEMO_INSTANTCASTANIMATIONENDED_H

#include "../../utils/Event.h"

class InstantCastAnimationEnded : public Event
{
public:
    InstantCastAnimationEnded(event_type type) : Event(type)
    {}
};

#endif //SFMLDEMO_INSTANTCASTANIMATIONENDED_H
