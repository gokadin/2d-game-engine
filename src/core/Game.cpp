#include "Game.h"

Game::Game(int screenWidth, int screenHeight)
{
    dataProvider = new DataProvider(state, screenWidth, screenHeight);
    dataProvider->load();
    actionDispatcher = new ActionDispatcher(state);
    updateDispatcher = new UpdateDispatcher(state);
    animationDispatcher = new AnimationDispatcher(state);
    renderDispatcher = new RenderDispatcher(state);
    inputManager = new InputManager(actionDispatcher);
}

Game::~Game()
{
    delete dataProvider;
    delete inputManager;
    delete actionDispatcher;
    delete updateDispatcher;
    delete animationDispatcher;
    delete renderDispatcher;
}

void Game::processEvent(sf::Event event)
{
    inputManager->processEvent(event);
}

void Game::update()
{
    updateDispatcher->update();
    animationDispatcher->update();
}

void Game::draw(sf::RenderWindow *window)
{
    renderDispatcher->render(window);
}
