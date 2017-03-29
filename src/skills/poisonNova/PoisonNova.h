#ifndef SFMLDEMO_POISONNOVA_H
#define SFMLDEMO_POISONNOVA_H

#include "../../data/definitions/map/MapState.h"
#include "../ProjectileSkill.h"

class PoisonNova : public ProjectileSkill
{
public:
    PoisonNova(MapState *mapState);

    void update();
    void draw(sf::RenderWindow *window);
    bool canActivate();
    void activate(int targetX, int targetY);
    void handleCharacterStatsChanged(CharacterStats *characterStats);

private:
    const int PROJECTILES_PER_CAST = 32;

    MapState *m_mapState;
    sf::Texture m_projectileTexture;
};

#endif //SFMLDEMO_POISONNOVA_H
