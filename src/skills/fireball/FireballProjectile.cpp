#include "FireballProjectile.h"

FireballProjectile::FireballProjectile(sf::Texture *texture, MapState *mapState, int targetX, int targetY):
        Projectile(texture, mapState, Engine::CX + mapState->x(), Engine::CY + mapState->y(), targetX, targetY)
{}

void FireballProjectile::update()
{
    if (m_phase == projectile_phase::ACTIVATED)
    {
        m_phase = projectile_phase::FLYING;

        double angle = atan2(m_targetY - Engine::CY, m_targetX - Engine::CX);
        m_flyingSpeedX = FLY_SPEED * (float)cos(angle);
        m_flyingSpeedY = FLY_SPEED * (float)sin(angle);
    }

    if (m_phase == projectile_phase::FLYING)
    {
        m_x = m_x + m_flyingSpeedX;
        m_y = m_y + m_flyingSpeedY;
    }
}

void FireballProjectile::draw(sf::RenderWindow *window)
{
    updateSprite();

    window->draw(m_sprite);
}

void FireballProjectile::updateSprite()
{
    m_sprite.setTextureRect(sf::IntRect(m_spriteOffsetX, SPRITE_OFFSET_Y, SPRITE_WIDTH, SPRITE_HEIGHT));
    m_sprite.setPosition(sf::Vector2f(m_x - m_mapState->x(), m_y - m_mapState->y()));
}
