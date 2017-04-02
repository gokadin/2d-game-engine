#ifndef SFMLDEMO_QUESTS_H
#define SFMLDEMO_QUESTS_H

#include "../../core/GameComponent.h"

class Quests : public GameComponent
{
public:
    Quests();
    ~Quests();

    void update();
    void draw(sf::RenderWindow *window);
};

#endif //SFMLDEMO_QUESTS_H
