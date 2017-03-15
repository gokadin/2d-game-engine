#include "Game.h"

Game::Game(sf::RenderWindow *window):
        m_window(window)
{
    dataProvider = new DataProvider();
    character = new Character();
    map = new Map(window, character->stats());
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
            else if (event.mouseButton.button == sf::Mouse::Button::Left)
            {
                map->startMoving();
            }
            break;
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Button::Left)
            {
                map->stopMovingOnPoint(event.mouseButton.x, event.mouseButton.y);
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

void Game::draw()
{
    map->draw(m_window);
    character->draw(m_window);
    skillManager->draw(m_window);
}
