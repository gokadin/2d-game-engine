#ifndef SFMLDEMO_MONSTER_H
#define SFMLDEMO_MONSTER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../data/definitions/map/MapState.h"
#include "../enums/monsters/MonsterPhase.h"

class Monster
{
public:
    Monster(sf::Texture *texture, MapState *mapState, float x, float y);

    virtual void update() = 0;
    virtual void draw(sf::RenderWindow *window) = 0;

    virtual void inflictDamage(int damage);

protected:
    sf::Texture *m_texture;
    sf::Sprite m_sprite;
    MapState *m_mapState;
    float m_x;
    float m_y;
    int m_life;
    monster_phase m_phase;
};

#endif //SFMLDEMO_MONSTER_H
