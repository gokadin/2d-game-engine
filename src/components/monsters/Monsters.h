#ifndef SFMLDEMO_MONSTERS_H
#define SFMLDEMO_MONSTERS_H

#include "../../core/GameComponent.h"
#include "../../monsters/MonsterManager.h"
#include "../../data/definitions/map/MapState.h"
#include "../../data/definitions/map/MapBounds.h"

class Monsters : public GameComponent
{
public:
    Monsters(MapState *mapState, MapBounds *bounds);
    ~Monsters();

    void update();
    void draw(sf::RenderWindow *window);
    Monster* findMonster(int id);

private:
    std::vector<MonsterManager *> m_monsterManagers;
    MapState *m_mapState;
    MapBounds *m_bounds;
};

#endif //SFMLDEMO_MONSTERS_H
