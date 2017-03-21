#ifndef SFMLDEMO_MONSTER_H
#define SFMLDEMO_MONSTER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../data/definitions/map/MapState.h"
#include "../enums/monsters/MonsterPhase.h"
#include "../data/definitions/map/MapBounds.h"


class Monster
{
public:
    Monster(int id, sf::Texture *texture, MapState *mapState, MapBounds *mapBounds);

    virtual void update() = 0;
    virtual void draw(sf::RenderWindow *window) = 0;

    inline int hitBoxWidth() { return m_hitBoxWidth; }
    inline int hitBoxHeight() { return m_hitBoxHeight; }
    inline float x() { return m_x; }
    inline float y() { return m_y; }
    inline int id() { return m_id; }
    inline bool isAlive() { return m_phase != monster_phase::DEAD && m_phase != monster_phase::INACTIVE; }
    inline bool isInactive() { return m_phase == monster_phase::INACTIVE; }
    inline bool isDead() { return m_phase == monster_phase::DEAD; }

    inline void setPosition(float x, float y) { m_x = x; m_y = y; }
    inline void setHitBox(int width, int height) { m_hitBoxWidth = width; m_hitBoxHeight = height; }

    virtual void inflictDamage(int damage);
    void addToMap();

protected:
    int m_id;
    sf::Texture *m_texture;
    sf::Sprite m_sprite;
    MapState *m_mapState;
    MapBounds *m_mapBounds;
    float m_x;
    float m_y;
    int m_life;
    monster_phase m_phase;
    int m_hitBoxWidth;
    int m_hitBoxHeight;
};

#endif //SFMLDEMO_MONSTER_H
