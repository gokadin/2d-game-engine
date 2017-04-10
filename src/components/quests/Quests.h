#ifndef SFMLDEMO_QUESTS_H
#define SFMLDEMO_QUESTS_H

#include "../../core/GameComponent.h"
#include "tracking/QuestTracker.h"

class Quests : public GameComponent
{
public:
    Quests(GameFonts *fonts);
    ~Quests();

    void update();
    void draw(sf::RenderWindow *window);

private:
    QuestTracker m_tracker;
};

#endif //SFMLDEMO_QUESTS_H
