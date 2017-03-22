#include "Zombie.h"

Zombie::Zombie(int id, sf::Texture *texture, MapState *mapState, MapBounds *mapBounds):
        Monster(id, texture, mapState, mapBounds)
{
    m_sprite.setTextureRect(sf::IntRect(0, 0, 56, 112));
}

void Zombie::update()
{

}

void Zombie::draw(sf::RenderWindow *window)
{
    if (m_phase == monster_phase::DEAD)
    {
        return;
    }

    m_sprite.setPosition(sf::Vector2f(m_x - m_mapState->x(), m_y - m_mapState->y()));

    window->draw(m_sprite);
}
