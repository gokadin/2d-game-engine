#include "Minion.h"

Minion::Minion(int id, sf::Texture *texture, MapState *mapState, MapBounds *mapBounds):
        Monster(id, texture, mapState, mapBounds)
{
    m_sprite.setTextureRect(sf::IntRect(0, 0, 64, 128));

    setIdleMoveSpeed(1.0f);
    setAggroMoveSpeed(1.5f);
    setAggroRange(50);
}

void Minion::draw(sf::RenderWindow *window)
{
    if (m_phase == monster_phase::DEAD)
    {
        return;
    }

    m_relX = m_x - m_mapState->x();
    m_relY = m_y - m_mapState->y();
    m_sprite.setPosition(sf::Vector2f(m_relX - m_hitBoxWidth / 2, m_relY - m_hitBoxHeight));

    window->draw(m_sprite);
}
