#ifndef SFMLDEMO_GAME_H
#define SFMLDEMO_GAME_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../data/DataProvider.h"
#include "../components/character/Character.h"
#include "../components/skills/SkillManager.h"
#include "../components/map/Map.h"

class Game
{
public:
    Game(sf::RenderWindow *window);
    ~Game();

    void processEvent(sf::Event event);
    void update();
    void draw();

private:
    sf::RenderWindow *m_window;
    DataProvider *dataProvider;
    Map *map;
    Character *character;
    SkillManager *skillManager;

    void load();
    void subscribeComponents();
};

#endif //SFMLDEMO_GAME_H
