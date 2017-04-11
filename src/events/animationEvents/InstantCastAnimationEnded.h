#ifndef SFMLDEMO_INSTANTCASTANIMATIONENDED_H
#define SFMLDEMO_INSTANTCASTANIMATIONENDED_H

#include "../../utils/Event.h"

class InstantCastAnimationEnded : public Event
{
public:
    InstantCastAnimationEnded()
            : Event(event_type::INSTANT_CAST_ANIMATION_ENDED)
    {}
};

#endif //SFMLDEMO_INSTANTCASTANIMATIONENDED_H
