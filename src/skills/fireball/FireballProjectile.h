#ifndef SFMLDEMO_FIREBALLPROJECTILE_H
#define SFMLDEMO_FIREBALLPROJECTILE_H

#include "../Projectile.h"
#include "../../data/definitions/map/MapState.h"

class FireballProjectile : public Projectile
{
public:
    FireballProjectile(sf::Texture *texture, MapState *mapState, int targetX, int targetY);

    void update();
    void draw(sf::RenderWindow *window);

private:
    const int SPRITE_WIDTH = 32;
    const int SPRITE_HEIGHT = 32;
    const int SPRITE_OFFSET_Y = 0;
    const int HIT_RADIUS = 30;
    const int FLY_SPEED = 3;

    void updateSprite();
};

#endif //SFMLDEMO_FIREBALLPROJECTILE_H
