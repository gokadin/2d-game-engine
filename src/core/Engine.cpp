#include "Engine.h"
#include "../windows/ContextSwitcher.h"
#include "Actions.h"

const int UPDATE_INTERVAL_MU = 16000;
const int SECOND_IN_MU = 1000000;

Engine::Engine() {}

Engine::~Engine() {}

void Engine::run()
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1280, 720), "SFML works!");

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
    fpsText.setString("FPS 0");
    sf::Text updateText;
    updateText.setFont(font);
    updateText.setCharacterSize(18);
    updateText.setColor(sf::Color::Red);
    updateText.setPosition(sf::Vector2f(5.0f, 25.0f));
    updateText.setString("UPS 0");

    Actions *actions = new Actions();
    ContextSwitcher *contextSwitcher = new ContextSwitcher(actions);

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

            // change update method name for like process event or something
            actions->update(event);
        }

        int elapsedMu = clock.restart().asMicroseconds();

        updateAcc += elapsedMu;
        if (updateAcc >= UPDATE_INTERVAL_MU)
        {
            updateAcc = UPDATE_INTERVAL_MU - updateAcc;
            updateCounter++;

            contextSwitcher->update();
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
        //contextSwitcher->draw(window);
        window->draw(updateText);
        window->draw(fpsText);
        window->display();
    }

    delete actions;
    delete contextSwitcher;
    delete window;
}
