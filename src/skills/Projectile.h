#ifndef SFMLDEMO_PROJECTILE_H
#define SFMLDEMO_PROJECTILE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../enums/ProjectilePhase.h"
#include "../data/definitions/map/MapState.h"
#include "../monsters/Monster.h"

class Projectile
{
public:
    Projectile(sf::Texture *texture, MapState *mapState, float initialX, float initialY, int targetX, int targetY,
               int damage);
    virtual ~Projectile();

    virtual void update() = 0;
    virtual void draw(sf::RenderWindow *window) = 0;
    virtual void hit() = 0;
    virtual void cancel();

    inline bool isActive() { return m_phase != projectile_phase::INACTIVE; }
    inline bool isFlying() { return m_phase == projectile_phase::FLYING; }
    inline bool isHitting() { return m_phase == projectile_phase::HITTING; }
    inline float ax() { return m_x; }
    inline float ay() { return m_y; }
    inline int damage() { return m_damage; }

    virtual void hitMonster(Monster *monster);

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
    int m_spriteOffsetY;
    float m_flyingSpeedX;
    float m_flyingSpeedY;
    int m_damage;
};

#endif //SFMLDEMO_PROJECTILE_H
