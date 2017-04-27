#ifndef SFMLDEMO_MONSTER_H
#define SFMLDEMO_MONSTER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../data/definitions/map/MapState.h"
#include "../enums/monsters/MonsterPhase.h"
#include "../data/definitions/map/MapBounds.h"
#include "../effects/EffectManager.h"
#include "../common/MortalEntity.h"
#include "../utils/observable/Observable.h"
#include "../enums/monsters/MonsterType.h"

class Monster : public MortalEntity, public Observable
{
public:
    Monster(int id, monster_type type, uint16_t experienceWorth, sf::Texture *texture, MapState *mapState,
            MapBounds *mapBounds);

    virtual void draw(sf::RenderWindow *window) = 0;
    virtual void update();
    virtual void resurrect();

    inline monster_type type() { return m_type; }
    inline uint16_t experienceWorth() { return m_experienceWorth; }
    inline int hitBoxWidth() { return m_hitBoxWidth; }
    inline int hitBoxHeight() { return m_hitBoxHeight; }
    inline float x() { return m_cx; }
    inline float y() { return m_cy; }
    inline int id() { return m_id; }
    inline bool isAlive() { return m_phase != monster_phase::DEAD && m_phase != monster_phase::INACTIVE; }
    inline monster_phase phase() { return m_phase; }
    inline float idleMoveSpeed() { return m_idleMoveSpeed; }
    inline float aggroMoveSpeed() { return m_aggroMoveSpeed; }
    inline int aggroRange() { return m_aggroRange; }
    inline EffectManager& effectManager() { return m_effectManager; }

    inline void setPosition(float x, float y) { m_cx = x; m_cy = y; }
    inline void setHitBox(int width, int height) { m_hitBoxWidth = width; m_hitBoxHeight = height; }
    inline void setIdleMoveSpeed(float idleMoveSpeed) { m_idleMoveSpeed = idleMoveSpeed; }
    inline void setAggroMoveSpeed(float aggroMoveSpeed) { m_aggroMoveSpeed = aggroMoveSpeed; }
    inline void setAggroRange(int aggroRange) { m_aggroRange = aggroRange; }
    inline void setPhase(monster_phase phase) { m_phase = phase; }
    inline void move(float diffX, float diffY)
    {
        m_mapBounds->removeBounds(m_cx, m_cy, m_hitBoxWidth, m_id);
        m_cx += diffX;
        m_cy += diffY;
        m_mapBounds->addBounds(m_cx, m_cy, m_hitBoxWidth, m_id);

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
    float m_cx;
    float m_cy;
    monster_phase m_phase;
    int m_hitBoxWidth;
    int m_hitBoxHeight;
    float m_idleMoveSpeed;
    float m_aggroMoveSpeed;
    int m_aggroRange;

    virtual void die();

private:
    monster_type m_type;
    uint16_t m_experienceWorth;
};

#endif //SFMLDEMO_MONSTER_H
