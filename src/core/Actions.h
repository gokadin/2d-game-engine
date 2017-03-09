#ifndef SFMLDEMO_ACTIONS_H
#define SFMLDEMO_ACTIONS_H

#include <SFML/Window/Event.hpp>
#include "../utils/Observable.h"
#include "../utils/Event.h"
#include "states/MapState.h"
#include "states/GameState.h"

class Actions : public Observable
{
public:
    Actions(GameState *gameState);
    ~Actions();

    void processEvent(sf::Event event);

private:
    GameState *gameState;

    void processKeyPressed(sf::Keyboard::Key code);
    void processKeyReleased(sf::Keyboard::Key code);

    void processKeyPressedW();
    void processKeyReleasedW();
    void processKeyPressedS();
    void processKeyReleasedS();
    void processKeyPressedD();
    void processKeyReleasedD();
    void processKeyPressedA();
    void processKeyReleasedA();
};

#endif //SFMLDEMO_ACTIONS_H
