#include "PoisonNovaProjectile.h"
#include "../../effects/general/DamageOverTime.h"

PoisonNovaProjectile::PoisonNovaProjectile(sf::Texture *texture, MapState *mapState, double angle, int damage):
        Projectile(texture, mapState, Engine::HALF_SCREEN_WIDTH + mapState->x(), Engine::HALF_SCREEN_HEIGHT + mapState->y(), 0, 0, damage),
        m_angle(angle)
{}

void PoisonNovaProjectile::update()
{
    if (m_phase == projectile_phase::ACTIVATED)
    {
        m_phase = projectile_phase::FLYING;

        m_flyingSpeedX = FLY_SPEED * (float)cos(m_angle);
        m_flyingSpeedY = FLY_SPEED * (float)sin(m_angle);
    }

    if (m_phase == projectile_phase::FLYING)
    {
        m_x = m_x + m_flyingSpeedX;
        m_y = m_y + m_flyingSpeedY;
    }

    if (m_phase == projectile_phase::HITTING)
    {
        m_explFrameCounter++;
        if (m_explFrameCounter == EXPL_FRAMES_BETWEEN)
        {
            m_explFrameCounter = 0;
            if (m_spriteOffsetX == EXPL_COUNT - 1)
            {
                cancel();
            }

            m_spriteOffsetX++;
        }
    }
}

void PoisonNovaProjectile::draw(sf::RenderWindow *window)
{
    updateSprite();

    window->draw(m_sprite);
}

void PoisonNovaProjectile::updateSprite()
{
    m_sprite.setTextureRect(sf::IntRect(m_spriteOffsetX * SPRITE_WIDTH, m_spriteOffsetY * SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT));
    m_sprite.setPosition(sf::Vector2f(m_x - m_mapState->x(), m_y - m_mapState->y()));
}

void PoisonNovaProjectile::hit()
{
    m_phase = projectile_phase::HITTING;
    m_spriteOffsetY = 1;
    m_spriteOffsetX = 0;
    m_explFrameCounter = 0;
}

void PoisonNovaProjectile::hitMonster(Monster *monster)
{
    monster->effectManager().refresh("POISON_NOVA", new DamageOverTime(monster, m_damage, 2000));
}
