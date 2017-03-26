#include "Game.h"

Game::Game(sf::RenderWindow *window):
        m_window(window), m_mousePressWasOnUI(false)
{
    m_dataProvider = new DataProvider();
    m_character = new Character();
    m_map = new Map(window, m_character->stats(), m_character->graphics(), m_character->state());
    m_dataProvider->loadMap(m_map);
    m_monsters = new Monsters(m_map->state(), m_map->bounds(), m_character->graphics());
    m_skillManager = new SkillManager(m_map->state(), m_map->bounds(), m_map->graphics(), m_character->graphics(),
                                      m_character->stats(), m_monsters);
    m_userInterface = new UserInterface(m_character->equipmentManager());

    load();
    subscribeComponents();
}

Game::~Game()
{
    delete m_dataProvider;
    delete m_map;
    delete m_character;
    delete m_skillManager;
    delete m_monsters;
    delete m_userInterface;
}

void Game::load()
{
    m_dataProvider->loadCharacter(m_character);
    m_dataProvider->loadSkills(m_skillManager);
}

void Game::subscribeComponents()
{
    m_skillManager->subscribe(m_character);
    m_character->stats()->subscribe(m_skillManager);

    m_character->stats()->addSpellPower(0); // temp
}

void Game::processEvent(sf::Event &event)
{
    switch (event.type)
    {
        case sf::Event::MouseButtonPressed:
            if (m_userInterface->isMouseOnUI(event.mouseButton.x, event.mouseButton.y))
            {
                m_mousePressWasOnUI = true;

                m_userInterface->processEvent(event);
            }
            else if (event.mouseButton.button == sf::Mouse::Button::Right)
            {
                m_skillManager->activate(0, event.mouseButton.x, event.mouseButton.y);
            }
            else if (event.mouseButton.button == sf::Mouse::Button::Left)
            {
                m_character->state()->startMoving();
            }
            break;
        case sf::Event::MouseButtonReleased:
            if (m_userInterface->isMouseOnUI(event.mouseButton.x, event.mouseButton.y) || m_mousePressWasOnUI)
            {
                m_userInterface->processEvent(event);
            }
            else if (event.mouseButton.button == sf::Mouse::Button::Left)
            {
                m_character->state()->stopOnPoint(event.mouseButton.x, event.mouseButton.y);
            }

            m_mousePressWasOnUI = false;
            break;
        case sf::Event::KeyPressed:
            switch (event.key.code)
            {
                case sf::Keyboard::Escape:
                    if (m_userInterface->hasOpenWindows())
                    {
                        m_userInterface->closeOpenWindows();
                    }
                    else
                    {
                        m_window->close();
                    }
                    break;
                case sf::Keyboard::I:
                    m_userInterface->toggleInventory();
                    break;
            }
            break;
    }
}

void Game::update()
{
    m_map->update();
    m_character->update();
    m_skillManager->update();
    m_monsters->update();
    m_userInterface->update();
}

void Game::draw()
{
    m_map->draw(m_window);
    m_character->draw(m_window);
    m_skillManager->draw(m_window);
    m_monsters->draw(m_window);
    m_userInterface->draw(m_window);
}
