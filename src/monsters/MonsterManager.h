#ifndef SFMLDEMO_MONSTERMANAGER_H
#define SFMLDEMO_MONSTERMANAGER_H

#include <SFML/Graphics/Texture.hpp>
#include "Monster.h"
#include "../data/definitions/map/MapState.h"
#include "../data/definitions/map/MapBounds.h"
#include "../data/definitions/character/CharacterGraphics.h"

class MonsterManager
{
public:
    MonsterManager(int nextId, MapState *mapState, MapBounds *bounds, CharacterGraphics *characterGraphics);
    virtual ~MonsterManager();

    virtual void update();
    virtual void draw(sf::RenderWindow *window);

    inline Monster* findMonster(int id) { return m_monsters[id]; }

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

    void drawHealthBar(sf::RenderWindow *window, Monster *monster);
};

#endif //SFMLDEMO_MONSTERMANAGER_H
