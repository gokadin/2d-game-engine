#ifndef SFMLDEMO_SUMMONER_H
#define SFMLDEMO_SUMMONER_H

#include "../../Monster.h"

class Summoner : public Monster
{
public:
    Summoner(int id, sf::Texture *texture, MapState *mapState, MapBounds *mapBounds);

    void draw(sf::RenderWindow *window);
    void update();
    bool isReadyToResurrect();
    bool isInResurrectRange(Monster *minion);
    void resurrectMinion(Monster *minion);

protected:
    const int RESURRECT_DELAY_FRAMES = Engine::UPS * 3; // turn into skill
    const int RESURRECT_RANGE = 300;

    int m_resurrectTimer;
    Monster *m_minionToResurrect;
};

#endif //SFMLDEMO_SUMMONER_H
