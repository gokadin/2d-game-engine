#ifndef SFMLDEMO_FIREBALL_H
#define SFMLDEMO_FIREBALL_H

#include <SFML/Graphics/Texture.hpp>
#include "../ProjectileSkill.h"
#include "../../data/definitions/map/MapState.h"

class Fireball : public ProjectileSkill
{
public:
    Fireball(MapState *mapState);

    void update();
    void draw(sf::RenderWindow *window);
    bool canActivate();
    void activate(int targetX, int targetY);
    void handleCharacterStatsChanged(CharacterStats *characterStats);

private:
    MapState *m_mapState;
    sf::Texture m_projectileTexture;
};

#endif //SFMLDEMO_FIREBALL_H
