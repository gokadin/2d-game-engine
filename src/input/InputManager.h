#ifndef SFMLDEMO_INPUTMANAGER_H
#define SFMLDEMO_INPUTMANAGER_H

#include <SFML/Window/Event.hpp>
#include "../core/ActionDispatcher.h"

class InputManager
{
public:
    InputManager(ActionDispatcher *dispatcher);

    void processEvent(sf::Event event);

private:
    ActionDispatcher *dispatcher;

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

#endif //SFMLDEMO_INPUTMANAGER_H
