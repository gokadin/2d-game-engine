#ifndef SFMLDEMO_ZOMBIE_H
#define SFMLDEMO_ZOMBIE_H

#include "../../Monster.h"

class Zombie : public Monster
{
public:
    Zombie(int id, sf::Texture *texture, MapState *mapState, MapBounds *mapBounds);

    void update();
    void draw(sf::RenderWindow *window);
};

#endif //SFMLDEMO_ZOMBIE_H
