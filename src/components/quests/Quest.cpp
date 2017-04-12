#include "Quest.h"

Quest::Quest(quest_name name, std::string displayName)
        : m_name(name),
          m_displayName(displayName)
{}

Quest::~Quest()
{
    for (auto *objective : m_objectives)
    {
        delete objective;
    }
    m_objectives.clear();
}

void Quest::addObjective(Objective *objective)
{
    m_objectives.push_back(objective);
}

bool Quest::isCompleted()
{
    for (auto *objective : m_objectives)
    {
        if (!objective->isCompleted())
        {
            return false;
        }
    }

    return true;
}

void Quest::notify(std::shared_ptr<Event> event)
{
    for (auto *objective : m_objectives)
    {
        objective->notify(event);
    }
}
