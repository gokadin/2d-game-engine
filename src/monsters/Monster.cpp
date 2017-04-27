#include "Monster.h"
#include "../events/monsters/MonsterDiedEvent.h"

Monster::Monster(int id, monster_type type, uint16_t experienceWorth, sf::Texture *texture, MapState *mapState,
                 MapBounds *mapBounds)
        : m_id(id),
          m_type(type),
          m_experienceWorth(experienceWorth),
          m_texture(texture),
          m_mapState(mapState),
          m_mapBounds(mapBounds),
          m_cx(0),
          m_cy(0),
          m_phase(monster_phase::IDLE),
          m_hitBoxWidth(0),
          m_hitBoxHeight(0)
{
    m_sprite.setTexture(*texture);
}

void Monster::update()
{
    m_effectManager.update();
}

void Monster::inflictDamage(int damage)
{
    if (m_currentLife <= 0)
    {
        return;
    }

    m_currentLife -= damage;

    if (m_currentLife <= 0)
    {
        die();
    }
}

void Monster::addToMap()
{
    m_mapBounds->addBounds(m_cx, m_cy, m_hitBoxWidth, m_id);
}

void Monster::resurrect()
{
    if (m_phase != monster_phase::DEAD)
    {
        return;
    }

    m_phase = monster_phase::IDLE;
    m_currentLife = m_maxLife;
    addToMap();
}

void Monster::die()
{
    m_phase = monster_phase::DEAD;
    m_mapBounds->removeBounds(m_cx, m_cy, m_hitBoxWidth, m_id);
    notifyObservers(std::make_shared<MonsterDiedEvent>(this));
}
