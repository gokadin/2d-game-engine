#include "Monster.h"

Monster::Monster(sf::Texture *texture, MapState *mapState, float x, float y):
        m_texture(texture), m_mapState(mapState), m_x(x), m_y(y), m_life(100), m_phase(monster_phase::IDLE)
{
    m_sprite.setTexture(*texture);
}

void Monster::inflictDamage(int damage)
{
    m_life -= damage;

    if (m_life <= 0)
    {
        m_phase = monster_phase::INACTIVE_2;
    }
}
