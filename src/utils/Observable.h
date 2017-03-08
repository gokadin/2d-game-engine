#ifndef SFMLDEMO_OBSERVABLE_H
#define SFMLDEMO_OBSERVABLE_H

#include <vector>
#include <iostream>
#include "Observer.h"

class Observable
{
public:
    Observable() {}
    virtual ~Observable()
    {
        for (Observer *observer : observers)
        {
            observer = NULL;
            delete observer;
        }
        observers.clear();
    }

    inline void subscribe(Observer *observer) { observers.push_back(observer); }

protected:
    std::vector<Observer *> observers;

    virtual void notifyObservers(Event *event)
    {
        for (int i = 0; i < observers.size(); i++)
        {
            observers[i]->notify(event);
        }
    }
};

#endif //SFMLDEMO_OBSERVABLE_H
