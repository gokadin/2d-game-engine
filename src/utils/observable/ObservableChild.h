#ifndef SFMLDEMO_OBSERVABLECHILD_H
#define SFMLDEMO_OBSERVABLECHILD_H

#include "ChildObserver.h"

class ObservableChild
{
public:
    ObservableChild() {}
    virtual ~ObservableChild()
    {
        m_parent = nullptr;
        delete m_parent;
    }

    inline void subscribeParent(ChildObserver *observer) { m_parent = observer; }

protected:
    ChildObserver *m_parent;

    virtual void notifyParent(std::shared_ptr<Event> event)
    {
        if (m_parent != nullptr)
        {
            m_parent->handleChildEvent(event);
        }
    }
};

#endif //SFMLDEMO_OBSERVABLECHILD_H
