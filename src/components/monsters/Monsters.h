#ifndef SFMLDEMO_MONSTERS_H
#define SFMLDEMO_MONSTERS_H

#include "../../core/GameComponent.h"
#include "../../monsters/MonsterManager.h"
#include "../../data/definitions/map/MapState.h"
#include "../../data/definitions/map/MapBounds.h"

class Monsters : public GameComponent, public Observer, public Observable
{
public:
    Monsters(MapState *mapState, MapBounds *bounds, CharacterGraphics *characterGraphics);
    ~Monsters();

    void update();
    void draw(sf::RenderWindow *window);
    Monster* findMonster(int id);
    void handleEvent(std::shared_ptr<Event> event);

private:
    std::vector<MonsterManager *> m_monsterManagers;
    MapState *m_mapState;
    MapBounds *m_bounds;
    CharacterGraphics *m_characterGraphics;
};

#endif //SFMLDEMO_MONSTERS_H
