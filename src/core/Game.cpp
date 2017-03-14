#include "Game.h"

Game::Game(int screenWidth, int screenHeight)
{
    dataProvider = new DataProvider();
    map = new Map();
    character = new Character();
    skillManager = new SkillManager();

    load();
    subscribeComponents();
}

Game::~Game()
{
    delete dataProvider;
    delete map;
    delete character;
    delete skillManager;
}

void Game::load()
{
    dataProvider->loadMap(map);
    dataProvider->loadCharacter(character);
    dataProvider->loadSkills(skillManager);
}

void Game::subscribeComponents()
{
    skillManager->subscribe(character);
}

void Game::processEvent(sf::Event event)
{
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
    map->update();
    character->update();
    skillManager->update();
}

void Game::draw(sf::RenderWindow *window)
{
    map->draw(window);
    character->draw(window);
    skillManager->draw(window);
}
