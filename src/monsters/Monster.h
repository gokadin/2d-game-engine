#ifndef SFMLDEMO_MONSTER_H
#define SFMLDEMO_MONSTER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../data/definitions/map/MapState.h"
#include "../enums/monsters/MonsterPhase.h"
#include "../data/definitions/map/MapBounds.h"
#include "../effects/EffectManager.h"
#include "../common/MortalEntity.h"

class Monster : public MortalEntity
{
public:
    Monster(int id, sf::Texture *texture, MapState *mapState, MapBounds *mapBounds);

    virtual void draw(sf::RenderWindow *window) = 0;
    virtual void update();
    virtual void resurect();

    inline int hitBoxWidth() { return m_hitBoxWidth; }
    inline int hitBoxHeight() { return m_hitBoxHeight; }
    inline float x() { return m_x; }
    inline float y() { return m_y; }
    inline int id() { return m_id; }
    inline bool isAlive() { return m_phase != monster_phase::DEAD && m_phase != monster_phase::INACTIVE; }
    inline monster_phase phase() { return m_phase; }
    inline float idleMoveSpeed() { return m_idleMoveSpeed; }
    inline float aggroMoveSpeed() { return m_aggroMoveSpeed; }
    inline int aggroRange() { return m_aggroRange; }
    inline EffectManager& effectManager() { return m_effectManager; }

    inline void setPosition(float x, float y) { m_x = x; m_y = y; }
    inline void setHitBox(int width, int height) { m_hitBoxWidth = width; m_hitBoxHeight = height; }
    inline void setIdleMoveSpeed(float idleMoveSpeed) { m_idleMoveSpeed = idleMoveSpeed; }
    inline void setAggroMoveSpeed(float aggroMoveSpeed) { m_aggroMoveSpeed = aggroMoveSpeed; }
    inline void setAggroRange(int aggroRange) { m_aggroRange = aggroRange; }
    inline void setPhase(monster_phase phase) { m_phase = phase; }
    inline void move(float diffX, float diffY)
    {
        m_mapBounds->removeBounds(m_x - m_hitBoxWidth / 2, m_y - m_hitBoxHeight, m_hitBoxWidth, m_hitBoxHeight, m_id);
        m_x += diffX;
        m_y += diffY;
        m_mapBounds->addBounds(m_x - m_hitBoxWidth / 2, m_y - m_hitBoxHeight, m_hitBoxWidth, m_hitBoxHeight, m_id);

        // clean this up
    }

    virtual void inflictDamage(int damage);
    void addToMap();

protected:
    int m_id;
    sf::Texture *m_texture;
    sf::Sprite m_sprite;
    MapState *m_mapState;
    MapBounds *m_mapBounds;
    EffectManager m_effectManager;
    float m_x;
    float m_y;
    monster_phase m_phase;
    int m_hitBoxWidth;
    int m_hitBoxHeight;
    float m_idleMoveSpeed;
    float m_aggroMoveSpeed;
    int m_aggroRange;
};

#endif //SFMLDEMO_MONSTER_H
