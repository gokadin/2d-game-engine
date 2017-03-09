#include "InputManager.h"

InputManager::InputManager(ActionDispatcher *dispatcher):
        dispatcher(dispatcher)
{}

void InputManager::processEvent(sf::Event event){
    switch (event.type)
    {
        case sf::Event::KeyPressed:
            processKeyPressed(event.key.code);
            break;
        case sf::Event::KeyReleased:
            processKeyReleased(event.key.code);
            break;
    }
}

void InputManager::processKeyPressed(sf::Keyboard::Key code)
{
    switch (code)
    {
        case sf::Keyboard::W:
            processKeyPressedW();
            break;
        case sf::Keyboard::S:
            processKeyPressedS();
            break;
        case sf::Keyboard::D:
            processKeyPressedD();
            break;
        case sf::Keyboard::A:
            processKeyPressedA();
            break;
    }
}

void InputManager::processKeyReleased(sf::Keyboard::Key code)
{
    switch (code)
    {
        case sf::Keyboard::W:
            processKeyReleasedW();
            break;
        case sf::Keyboard::S:
            processKeyReleasedS();
            break;
        case sf::Keyboard::D:
            processKeyReleasedD();
            break;
        case sf::Keyboard::A:
            processKeyReleasedA();
            break;
    }
}

void InputManager::processKeyPressedW()
{
    dispatcher->dispatch(action_types::CHARACTER_MOVE_UP);
}

void InputManager::processKeyReleasedW()
{
    dispatcher->dispatch(action_types::CHARACTER_STOP_UP);
}

void InputManager::processKeyPressedS()
{
    dispatcher->dispatch(action_types::CHARACTER_MOVE_DOWN);
}

void InputManager::processKeyReleasedS()
{
    dispatcher->dispatch(action_types::CHARACTER_STOP_DOWN);
}

void InputManager::processKeyPressedD()
{
    dispatcher->dispatch(action_types::CHARACTER_MOVE_RIGHT);
}

void InputManager::processKeyReleasedD()
{
    dispatcher->dispatch(action_types::CHARACTER_STOP_RIGHT);
}

void InputManager::processKeyPressedA()
{
    dispatcher->dispatch(action_types::CHARACTER_MOVE_LEFT);
}

void InputManager::processKeyReleasedA()
{
    dispatcher->dispatch(action_types::CHARACTER_STOP_LEFT);
}
