#ifndef SFMLDEMO_ZOMBIE_H
#define SFMLDEMO_ZOMBIE_H

#include "../../Monster.h"

class Zombie : public Monster
{
public:
    Zombie(sf::Texture *texture, MapState *mapState, float x, float y);

    void update();
    void draw(sf::RenderWindow *window);
};

#endif //SFMLDEMO_ZOMBIE_H
