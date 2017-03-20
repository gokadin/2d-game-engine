#include "Projectile.h"

Projectile::Projectile(sf::Texture *texture, MapState *mapState, float initialX, float initialY, int targetX, int targetY):
        m_phase(projectile_phase::ACTIVATED), m_texture(texture), m_x(initialX), m_y(initialY), m_targetX(targetX),
        m_targetY(targetY), m_spriteOffsetX(0), m_spriteOffsetY(0), m_initialMapX(mapState->x()),
        m_initialMapY(mapState->y()), m_mapState(mapState), m_flyingSpeedX(0.0f), m_flyingSpeedY(0.0f)
{
    m_sprite.setTexture(*texture);
}

Projectile::~Projectile()
{
    delete m_texture;
}

void Projectile::cancel()
{
    m_phase = projectile_phase::INACTIVE;
}