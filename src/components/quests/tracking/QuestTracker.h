#ifndef SFMLDEMO_QUESTTRACKER_H
#define SFMLDEMO_QUESTTRACKER_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../../../utils/font/GameFonts.h"
#include "../../../enums/quests/QuestName.h"
#include "../Quest.h"
#include "../../../utils/Observable.h"

class QuestTracker : public Observable
{
public:
    QuestTracker();
    ~QuestTracker();

    void update();
    void acceptQuest(Quest *quest);

private:
    std::map<quest_name, Quest *> m_quests;
    Quest *m_activeQuest;
};

#endif //SFMLDEMO_QUESTTRACKER_H
