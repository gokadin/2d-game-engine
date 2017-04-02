#include <iostream>
#include "Engine.h"
#include "Game.h"
#include "../utils/font/GameFonts.h"

Engine::Engine() {}

Engine::~Engine() {}

void Engine::run()
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Chrono");

    auto gameFonts = new GameFonts();

    sf::Text fpsText;
    fpsText.setFont(gameFonts->getDefault());
    fpsText.setCharacterSize(18);
    fpsText.setColor(sf::Color::Red);
    fpsText.setPosition(sf::Vector2f(5.0f, 5.0f));
    fpsText.setString("FPS --");
    sf::Text updateText;
    updateText.setFont(gameFonts->getDefault());
    updateText.setCharacterSize(18);
    updateText.setColor(sf::Color::Red);
    updateText.setPosition(sf::Vector2f(5.0f, 25.0f));
    updateText.setString("UPS --");

    Game *game = new Game(window, gameFonts);

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
            if (event.type == sf::Event::Closed)
            {
                window->close();
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

        game->draw();
        window->draw(updateText);
        window->draw(fpsText);

        window->display();

        sf::sleep(sf::milliseconds(1));
    }

    delete game;
    delete window;
    delete gameFonts;
}
