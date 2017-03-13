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

    character = new Character();
    dataProvider->loadCharacter(character);
    skillManager = new SkillManager();
    dataProvider->loadSkills(skillManager);
    skillManager->subscribe(character);
}

Game::~Game()
{
    delete dataProvider;
    delete inputManager;
    delete actionDispatcher;
    delete updateDispatcher;
    delete animationDispatcher;
    delete renderDispatcher;

    delete character;
    delete skillManager;
}

void Game::processEvent(sf::Event event)
{
    inputManager->processEvent(event);

    switch (event.type)
    {
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Button::Right)
            {
                skillManager->activate(0, event.mouseButton.x, event.mouseButton.y);
            }
            break;
    }
}

void Game::update()
{
    updateDispatcher->update();
    animationDispatcher->update();

    character->update();
    skillManager->update();
}

void Game::draw(sf::RenderWindow *window)
{
    renderDispatcher->render(window);

    character->draw(window);
    skillManager->draw(window);
}
