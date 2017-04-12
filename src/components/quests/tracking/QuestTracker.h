#ifndef SFMLDEMO_QUESTTRACKER_H
#define SFMLDEMO_QUESTTRACKER_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../../../utils/font/GameFonts.h"
#include "../../../enums/quests/QuestName.h"
#include "../Quest.h"
#include "../../../utils/Observable.h"

class QuestTracker : public Observable, public Observer
{
public:
    QuestTracker();
    ~QuestTracker();

    void update();
    void acceptQuest(Quest *quest);
    Quest *quest() { return m_quest; }
    void notify(std::shared_ptr<Event> event);

private:
    Quest *m_quest;
};

#endif //SFMLDEMO_QUESTTRACKER_H
