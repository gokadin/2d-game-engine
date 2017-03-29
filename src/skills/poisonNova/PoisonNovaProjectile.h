#ifndef SFMLDEMO_POISONNOVAPROJECTILE_H
#define SFMLDEMO_POISONNOVAPROJECTILE_H

#include "../Projectile.h"

class PoisonNovaProjectile : public Projectile
{
public:
    PoisonNovaProjectile(sf::Texture *texture, MapState *mapState, double angle, int damage);

    void update();
    void draw(sf::RenderWindow *window);
    void hit();
    void hitMonster(Monster *monster);

private:
    const int SPRITE_WIDTH = 32;
    const int SPRITE_HEIGHT = 32;
    const int HIT_RADIUS = 30;
    const int FLY_SPEED = 3;
    const int EXPL_COUNT = 4;
    const int EXPL_FRAMES_BETWEEN = 10;

    double m_angle;
    int m_explFrameCounter;

    void updateSprite();
};

#endif //SFMLDEMO_POISONNOVAPROJECTILE_H
