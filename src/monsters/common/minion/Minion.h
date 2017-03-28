#ifndef SFMLDEMO_MINION_H
#define SFMLDEMO_MINION_H

#include "../../Monster.h"

class Minion : public Monster
{
public:
    Minion(int id, sf::Texture *texture, MapState *mapState, MapBounds *mapBounds);

    void draw(sf::RenderWindow *window);
};

#endif //SFMLDEMO_MINION_H
