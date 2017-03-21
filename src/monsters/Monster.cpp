#include "Monster.h"

Monster::Monster(int id, sf::Texture *texture, MapState *mapState, MapBounds *mapBounds):
        m_id(id), m_texture(texture), m_mapState(mapState), m_mapBounds(mapBounds), m_x(0), m_y(0), m_life(100),
        m_phase(monster_phase::IDLE), m_hitBoxWidth(0), m_hitBoxHeight(0)
{
    m_sprite.setTexture(*texture);
}

void Monster::inflictDamage(int damage)
{
    if (m_life <= 0)
    {
        return;
    }

    m_life -= damage;

    if (m_life <= 0)
    {
        m_phase = monster_phase::DEAD;
        m_mapBounds->removeBounds(m_x - m_hitBoxWidth / 2, m_y - m_hitBoxHeight, m_hitBoxWidth, m_hitBoxHeight, m_id);
    }
}

void Monster::addToMap()
{
    m_mapBounds->addBounds(m_x - m_hitBoxWidth / 2, m_y - m_hitBoxHeight, m_hitBoxWidth, m_hitBoxHeight, m_id);
}
