#ifndef SFMLDEMO_OBSERVER_H
#define SFMLDEMO_OBSERVER_H

#include "Event.h"
#include <memory>

class Observer
{
public:
    virtual void handleEvent(std::shared_ptr<Event> event) = 0;
};

#endif //SFMLDEMO_OBSERVER_H
