#ifndef SFMLDEMO_OBJECTIVE_H
#define SFMLDEMO_OBJECTIVE_H

#include <string>
#include "../../utils/observable/Observer.h"
#include "../../utils/observable/Observable.h"

class Objective : public Observer, public Observable
{
public:
    Objective(std::string description, int totalCount);

    inline bool isCompleted() { return m_isCompleted; }
    inline std::string description() { return m_description; }
    inline int totalCount() { return m_totalCount; }
    inline int currentCount() { return m_currentCount; }

    virtual void handleEvent(std::shared_ptr<Event> event) = 0;

protected:
    bool m_isCompleted;
    int m_totalCount;
    int m_currentCount;

    void complete();

private:
    std::string m_description;
};

#endif //SFMLDEMO_OBJECTIVE_H
