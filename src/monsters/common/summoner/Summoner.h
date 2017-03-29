#ifndef SFMLDEMO_SUMMONER_H
#define SFMLDEMO_SUMMONER_H

#include "../../Monster.h"

class Summoner : public Monster
{
public:
    Summoner(int id, sf::Texture *texture, MapState *mapState, MapBounds *mapBounds);

    void draw(sf::RenderWindow *window);
    void resurectMinion(Monster *minion);
};

#endif //SFMLDEMO_SUMMONER_H
