#ifndef SFMLDEMO_QUEST_H
#define SFMLDEMO_QUEST_H

#include <vector>
#include "../../enums/quests/QuestName.h"
#include "Objective.h"
#include "../../utils/Observer.h"

class Quest : public Observer
{
public:
    Quest(quest_name name, const std::string &displayName);
    ~Quest();

    void notify(std::shared_ptr<Event> event);

    inline quest_name name() { return m_name; }
    inline const std::string &displayName() { return m_displayName; }
    inline std::vector<Objective *>& objectives() { return m_objectives; }

protected:
    void addObjective(Objective *objective);

private:
    quest_name m_name;
    std::string m_displayName;
    std::vector<Objective *> m_objectives;

    bool isCompleted();
};

#endif //SFMLDEMO_QUEST_H
