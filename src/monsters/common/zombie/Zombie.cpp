#include "Zombie.h"
#include "../../../utils/math/Coords.h"

Zombie::Zombie(int id, sf::Texture *texture, MapState *mapState, MapBounds *mapBounds):
        Monster(id, monster_type::ZOMBIE, 100, texture, mapState, mapBounds)
{
    m_sprite.setTextureRect(sf::IntRect(0, 0, 56, 112));
}

void Zombie::update()
{
    Monster::update();

    if (m_phase == monster_phase::DEAD)
    {
        return;
    }

    m_sprite.setPosition(Coords::toIsometric(m_cx, m_cy, m_mapState->x() - m_mapState->isometricOffsetX(), m_mapState->y()));
}

void Zombie::draw(sf::RenderWindow *window)
{
    if (m_phase == monster_phase::DEAD)
    {
        return;
    }

    window->draw(m_sprite);
}
