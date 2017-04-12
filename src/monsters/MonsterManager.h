#ifndef SFMLDEMO_MONSTERMANAGER_H
#define SFMLDEMO_MONSTERMANAGER_H

#include <SFML/Graphics/Texture.hpp>
#include "Monster.h"
#include "../data/definitions/map/MapState.h"
#include "../data/definitions/map/MapBounds.h"
#include "../data/definitions/character/CharacterGraphics.h"

class MonsterManager : public Observable, public Observer
{
public:
    MonsterManager(int nextId, MapState *mapState, MapBounds *bounds, CharacterGraphics *characterGraphics);
    virtual ~MonsterManager();

    virtual void update();
    virtual void draw(sf::RenderWindow *window);
    int totalAliveMonsters();
    Monster* findAnyDeadMonster();
    void notify(std::shared_ptr<Event> event);

    inline Monster* findMonster(int id) { return m_monsters[id]; }
    inline int totalMonsters() { return m_totalMonsters; }

protected:
    const int HEALTH_BAR_BOTTOM_MARGIN = 10;
    const int HEALTH_BAR_WIDTH = 80;
    const int HEALTH_BAR_HEIGHT = 5;

    sf::Texture m_texture;
    MapState *m_mapState;
    MapBounds *m_bounds;
    CharacterGraphics *m_characterGraphics;
    std::map<int, Monster *> m_monsters;
    sf::RectangleShape m_healthBarBackground;
    sf::RectangleShape m_healthBarForeground;

    int nextId();
    void addMonster(Monster *monster);

private:
    int m_nextId;
    int m_totalMonsters;

    void drawHealthBar(sf::RenderWindow *window, Monster *monster);
};

#endif //SFMLDEMO_MONSTERMANAGER_H
