#include "Game.h"

Game::Game(int width, int height)
{
    state = new GameState(width, height);
    dataProvider = new DataProvider(state);
    actionDispatcher = new ActionDispatcher(state);
    updateDispatcher = new UpdateDispatcher(state);
    renderDispatcher = new RenderDispatcher(state);
    inputManager = new InputManager(actionDispatcher);
}

Game::~Game()
{
    delete dataProvider;
    delete inputManager;
    delete actionDispatcher;
    delete updateDispatcher;
    delete renderDispatcher;
    delete state;
}

void Game::processEvent(sf::Event event)
{
    inputManager->processEvent(event);
}

void Game::update()
{
    updateDispatcher->update();
}

void Game::draw(sf::RenderWindow *window)
{
    renderDispatcher->render(window);
}
