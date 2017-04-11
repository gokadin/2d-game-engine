#ifndef SFMLDEMO_QUEST_H
#define SFMLDEMO_QUEST_H

#include "../../enums/quests/QuestName.h"

class Quest
{
public:
    Quest(quest_name name);

    inline quest_name name() { return m_name; }

private:
    quest_name m_name;
};

#endif //SFMLDEMO_QUEST_H
