#ifndef SFMLDEMO_OBSERVER_H
#define SFMLDEMO_OBSERVER_H

#include "Event.h"

class Observer
{
public:
    virtual void notify(Event *event) = 0;
};

#endif //SFMLDEMO_OBSERVER_H
