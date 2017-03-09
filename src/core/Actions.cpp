#include "Actions.h"

Actions::Actions(GameState *gameState) :
        gameState(gameState)
{}

Actions::~Actions() {}

void Actions::processEvent(sf::Event event){
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

void Actions::processKeyPressed(sf::Keyboard::Key code)
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

void Actions::processKeyReleased(sf::Keyboard::Key code)
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

void Actions::processKeyPressedW()
{
    if (!gameState->getMapState()->getIsMovingUp() && !gameState->getMapState()->getIsMovingDown())
    {
        gameState->getMapState()->setIsMovingUp(true);
    }
}

void Actions::processKeyReleasedW()
{
    if (gameState->getMapState()->getIsMovingUp())
    {
        gameState->getMapState()->setIsMovingUp(false);
    }
}

void Actions::processKeyPressedS()
{
    if (!gameState->getMapState()->getIsMovingDown() && !gameState->getMapState()->getIsMovingUp( ))
    {
        gameState->getMapState()->setIsMovingDown(true);
    }
}

void Actions::processKeyReleasedS()
{
    if (gameState->getMapState()->getIsMovingDown())
    {
        gameState->getMapState()->setIsMovingDown(false);
    }
}

void Actions::processKeyPressedD()
{
    if (!gameState->getMapState()->getIsMovingRight() && !gameState->getMapState()->getIsMovingLeft())
    {
        gameState->getMapState()->setIsMovingRight(true);
    }
}

void Actions::processKeyReleasedD()
{
    if (gameState->getMapState()->getIsMovingRight())
    {
        gameState->getMapState()->setIsMovingRight(false);
    }
}

void Actions::processKeyPressedA()
{
    if (!gameState->getMapState()->getIsMovingLeft() && !gameState->getMapState()->getIsMovingRight())
    {
        gameState->getMapState()->setIsMovingLeft(true);
    }
}

void Actions::processKeyReleasedA()
{
    if (gameState->getMapState()->getIsMovingLeft())
    {
        gameState->getMapState()->setIsMovingLeft(false);
    }
}
