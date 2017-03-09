#ifndef SFMLDEMO_GAME_H
#define SFMLDEMO_GAME_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "ActionDispatcher.h"
#include "../input/InputManager.h"
#include "../states/GameState.h"
#include "UpdateDispatcher.h"
#include "RenderDispatcher.h"
#include "../data/DataProvider.h"

class Game
{
public:
    Game(int screenWidth, int screenHeight);
    ~Game();

    void processEvent(sf::Event event);
    void update();
    void draw(sf::RenderWindow *window);

private:
    GameState *state;
    DataProvider *dataProvider;
    ActionDispatcher *actionDispatcher;
    UpdateDispatcher *updateDispatcher;
    RenderDispatcher *renderDispatcher;
    InputManager *inputManager;
};

#endif //SFMLDEMO_GAME_H
