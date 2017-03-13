#ifndef SFMLDEMO_GAME_H
#define SFMLDEMO_GAME_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../states/GameState.h"
#include "UpdateDispatcher.h"
#include "RenderDispatcher.h"
#include "../data/DataProvider.h"
#include "../components/character/Character.h"
#include "../components/skills/SkillManager.h"

class Game
{
public:
    Game(int screenWidth, int screenHeight);
    ~Game();

    void processEvent(sf::Event event);
    void update();
    void draw(sf::RenderWindow *window);

private:
    GameState state;
    DataProvider *dataProvider;
    UpdateDispatcher *updateDispatcher;
    RenderDispatcher *renderDispatcher;

    Character *character;
    SkillManager *skillManager;
};

#endif //SFMLDEMO_GAME_H
