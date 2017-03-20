#include "Zombie.h"

Zombie::Zombie(sf::Texture *texture, MapState *mapState, float x, float y):
        Monster(texture, mapState, x, y)
{}

void Zombie::update()
{

}

void Zombie::draw(sf::RenderWindow *window)
{
    if (m_phase == monster_phase::INACTIVE_2)
    {
        return;
    }

    m_sprite.setTextureRect(sf::IntRect(0, 0, 56, 112));
    m_sprite.setPosition(sf::Vector2f(m_x - m_mapState->x(), m_y - m_mapState->y()));

    window->draw(m_sprite);
}
