#include <iostream>
#include "Engine.h"
#include "Game.h"
#include "../data/IO/KeyValueReader.h"
#include "../data/IO/ArrayReader.h"

const int UPDATE_INTERVAL_MU = 7000;
const int SECOND_IN_MU = 1000000;
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

Engine::Engine() {}

Engine::~Engine() {}

void Engine::run()
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Chrono");

    sf::Font font;
    if (!font.loadFromFile("../assets/fonts/Roboto-Regular.ttf"))
    {
        std::cout << "Could not load font." << std::endl;
    }

    sf::Text fpsText;
    fpsText.setFont(font);
    fpsText.setCharacterSize(18);
    fpsText.setColor(sf::Color::Red);
    fpsText.setPosition(sf::Vector2f(5.0f, 5.0f));
    fpsText.setString("FPS --");
    sf::Text updateText;
    updateText.setFont(font);
    updateText.setCharacterSize(18);
    updateText.setColor(sf::Color::Red);
    updateText.setPosition(sf::Vector2f(5.0f, 25.0f));
    updateText.setString("UPS --");

    Game *game = new Game(SCREEN_WIDTH, SCREEN_HEIGHT);

    long elapsedMu = 0;
    int updateAcc = 0;
    int updateCounter = 0;
    int frameRateAcc = 0;
    int frameRateCounter = 0;
    sf::Clock clock;
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        window->close();
                    }
                    break;
            }

            game->processEvent(event);
        }

        elapsedMu = clock.restart().asMicroseconds();

        updateAcc += elapsedMu;
        if (updateAcc >= UPDATE_INTERVAL_MU)
        {
            updateAcc = UPDATE_INTERVAL_MU - updateAcc;
            updateCounter++;

            game->update();
        }

        frameRateAcc += elapsedMu;
        frameRateCounter++;
        if (frameRateAcc >= SECOND_IN_MU)
        {
            frameRateAcc -= SECOND_IN_MU;
            fpsText.setString("FPS " + std::to_string(frameRateCounter));
            frameRateCounter = 0;

            updateText.setString("UPS " + std::to_string(updateCounter));
            updateCounter = 0;
        }

        window->clear(sf::Color::Black);

        game->draw(window);
        window->draw(updateText);
        window->draw(fpsText);

        window->display();

        sf::sleep(sf::milliseconds(1));
    }

    delete game;
    delete window;
}
