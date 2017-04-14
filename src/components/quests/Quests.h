#ifndef SFMLDEMO_QUESTS_H
#define SFMLDEMO_QUESTS_H

#include "../../core/GameComponent.h"
#include "tracking/QuestTracker.h"
#include "../../utils/observable/Observer.h"

class Quests : public GameComponent, public Observer
{
public:
    Quests();
    ~Quests();

    void update();
    void draw(sf::RenderWindow *window);
    void handleEvent(std::shared_ptr<Event> event);

    inline QuestTracker* tracker() { return m_tracker; }

private:
    QuestTracker *m_tracker;

    Quest* createQuest(quest_name name);
};

#endif //SFMLDEMO_QUESTS_H
