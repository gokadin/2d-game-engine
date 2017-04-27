#include "Summoner.h"
#include "../../../utils/math/Distances.h"

Summoner::Summoner(int id, sf::Texture *texture, MapState *mapState, MapBounds *mapBounds)
        : Monster(id, monster_type::SUMMONER, 100, texture, mapState, mapBounds),
          m_resurrectTimer(0),
          m_minionToResurrect(nullptr)
{
    m_sprite.setTextureRect(sf::IntRect(0, 0, 64, 128));
}

void Summoner::draw(sf::RenderWindow *window)
{
    if (m_phase == monster_phase::DEAD)
    {
        return;
    }

    m_sprite.setPosition(sf::Vector2f(m_cx - m_mapState->x() - m_hitBoxWidth / 2, m_cy - m_mapState->y() - m_hitBoxHeight));

    window->draw(m_sprite);
}

void Summoner::update()
{
    Monster::update();

    if (m_resurrectTimer > 0)
    {
        if (m_resurrectTimer == 1 && m_minionToResurrect != nullptr)
        {
            if (!m_minionToResurrect->isAlive())
            {
                m_minionToResurrect->resurrect();
            }

            m_minionToResurrect = nullptr;
        }

        m_resurrectTimer--;
    }
}

bool Summoner::isReadyToResurrect()
{
    return m_resurrectTimer == 0;
}

bool Summoner::isInResurrectRange(Monster *minion)
{
    return Distances::isInRange(m_cx, m_cy, minion->x(), minion->y(), RESURRECT_RANGE);
}

void Summoner::resurrectMinion(Monster *minion)
{
    if (m_resurrectTimer != 0)
    {
        return;
    }

    m_minionToResurrect = minion;

    m_resurrectTimer = RESURRECT_DELAY_FRAMES;
}
