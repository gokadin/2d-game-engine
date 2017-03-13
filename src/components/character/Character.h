#ifndef SFMLDEMO_CHARACTER_H
#define SFMLDEMO_CHARACTER_H

#include "../../core/GameComponent.h"
#include "../../utils/Observer.h"

class Character : public GameComponent, public Observer
{
public:
    void update();
    void draw(sf::RenderWindow *window);
    void notify(Event *event);

private:
    // animations
    // renderer
    // updater
};

#endif //SFMLDEMO_CHARACTER_H
