#ifndef SFMLDEMO_FIREBALLPROJECTILE_H
#define SFMLDEMO_FIREBALLPROJECTILE_H

#include "../Projectile.h"
#include "../../data/definitions/map/MapState.h"

class FireballProjectile : public Projectile
{
public:
    FireballProjectile(sf::Texture *texture, MapState *mapState, int targetX, int targetY, int damage);

    void update();
    void draw(sf::RenderWindow *window);
    void hit();

private:
    const int SPRITE_WIDTH = 32;
    const int SPRITE_HEIGHT = 32;
    const int HIT_RADIUS = 30;
    const int FLY_SPEED = 3;
    const int EXPL_COUNT = 4;
    const int EXPL_FRAMES_BETWEEN = 10;

    int m_explFrameCounter;

    void updateSprite();
};

#endif //SFMLDEMO_FIREBALLPROJECTILE_H
