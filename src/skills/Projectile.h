#ifndef SFMLDEMO_PROJECTILE_H
#define SFMLDEMO_PROJECTILE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../enums/ProjectilePhase.h"
#include "../data/definitions/map/MapState.h"

class Projectile
{
public:
    Projectile(sf::Texture *texture, MapState *mapState, float initialX, float initialY, int targetX, int targetY);
    virtual ~Projectile();

    virtual void update() = 0;
    virtual void draw(sf::RenderWindow *window) = 0;

    inline bool isActive() { return m_phase != projectile_phase::INACTIVE; }
    inline bool isFlying() { return m_phase == projectile_phase::FLYING; }

protected:
    projectile_phase m_phase;
    sf::Texture *m_texture;
    sf::Sprite m_sprite;
    MapState *m_mapState;
    float m_x;
    float m_y;
    float m_initialMapX;
    float m_initialMapY;
    float m_targetX;
    float m_targetY;
    int m_spriteOffsetX;
    float m_flyingSpeedX;
    float m_flyingSpeedY;
};

#endif //SFMLDEMO_PROJECTILE_H
