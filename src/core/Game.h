#ifndef SFMLDEMO_GAME_H
#define SFMLDEMO_GAME_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "ActionDispatcher.h"
#include "../input/InputManager.h"
#include "../states/GameState.h"
#include "UpdateDispatcher.h"
#include "RenderDispatcher.h"

class Game
{
public:
    Game();
    ~Game();

    void processEvent(sf::Event event);
    void update();
    void draw(sf::RenderWindow *window);

private:
    GameState *state;
    ActionDispatcher *actionDispatcher;
    UpdateDispatcher *updateDispatcher;
    RenderDispatcher *renderDispatcher;
    InputManager *inputManager;
};

#endif //SFMLDEMO_GAME_H
