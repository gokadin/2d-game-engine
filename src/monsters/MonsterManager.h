#ifndef SFMLDEMO_MONSTERMANAGER_H
#define SFMLDEMO_MONSTERMANAGER_H

#include <SFML/Graphics/Texture.hpp>
#include "Monster.h"
#include "../data/definitions/map/MapState.h"

class MonsterManager
{
public:
    MonsterManager(MapState *mapState, std::vector<std::vector<int>> *bounds);
    virtual ~MonsterManager();

    virtual void update();
    virtual void draw(sf::RenderWindow *window);

    inline Monster* findMonster(int id) { return m_monsters[id]; }

protected:
    sf::Texture m_texture;
    MapState *m_mapState;
    std::vector<std::vector<int>> *m_bounds;

    void addMonster(Monster *monster);

private:
    std::map<int, Monster *> m_monsters;
    int m_nextId;
};

#endif //SFMLDEMO_MONSTERMANAGER_H
