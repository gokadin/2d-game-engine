#ifndef SFMLDEMO_EVENT_H
#define SFMLDEMO_EVENT_H

#include <string>

class Event
{
public:
    Event(std::string type)
    {
        this->type = type;
    }

    virtual ~Event() {}

    inline std::string getType() { return type; }

private:
    std::string type;
};

#endif //SFMLDEMO_EVENT_H
