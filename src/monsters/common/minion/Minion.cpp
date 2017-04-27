#include "Minion.h"

Minion::Minion(int id, sf::Texture *texture, MapState *mapState, MapBounds *mapBounds):
        Monster(id, monster_type::MINION, 75, texture, mapState, mapBounds)
{
    m_sprite.setTextureRect(sf::IntRect(0, 0, 64, 128));
}

void Minion::draw(sf::RenderWindow *window)
{
    if (m_phase == monster_phase::DEAD)
    {
        return;
    }

    m_sprite.setPosition(sf::Vector2f(m_cx - m_mapState->x() - m_hitBoxWidth / 2, m_cy - m_mapState->y() - m_hitBoxHeight));

    window->draw(m_sprite);
}
