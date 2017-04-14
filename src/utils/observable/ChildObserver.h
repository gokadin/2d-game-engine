#ifndef SFMLDEMO_CHILDOBSERVER_H
#define SFMLDEMO_CHILDOBSERVER_H

#include <memory>
#include "Event.h"

class ChildObserver
{
public:
    virtual void handleChildEvent(std::shared_ptr<Event> event) = 0;
};

#endif //SFMLDEMO_CHILDOBSERVER_H
