#include "Engine.h"
#include "../windows/ContextSwitcher.h"

Engine::Engine() {}

Engine::~Engine() {}

void Engine::run()
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");

    ContextSwitcher *contextSwitcher = new ContextSwitcher();

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
        }

        window->clear(sf::Color::Black);
        contextSwitcher->draw(window);
        window->display();
    }

    delete window;
}
