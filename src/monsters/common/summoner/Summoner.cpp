#include "Summoner.h"

Summoner::Summoner(int id, sf::Texture *texture, MapState *mapState, MapBounds *mapBounds):
        Monster(id, texture, mapState, mapBounds)
{
    m_sprite.setTextureRect(sf::IntRect(0, 0, 64, 128));
}

void Summoner::draw(sf::RenderWindow *window)
{
    if (m_phase == monster_phase::DEAD)
    {
        return;
    }

    m_sprite.setPosition(sf::Vector2f(m_x - m_mapState->x() - m_hitBoxWidth / 2, m_y - m_mapState->y() - m_hitBoxHeight));

    window->draw(m_sprite);
}

void Summoner::resurectMinion(Monster *minion)
{
    minion->resurect();
}
