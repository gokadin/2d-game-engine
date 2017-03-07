#include "Engine.h"
#include "../windows/ContextSwitcher.h"

Engine::Engine() {}

Engine::~Engine() {}

void Engine::run()
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1280, 720), "SFML works!");
    window->setFramerateLimit(60);

    ContextSwitcher *contextSwitcher = new ContextSwitcher();

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

            contextSwitcher->update(event);
        }

        window->clear(sf::Color::Black);
        contextSwitcher->draw(window);
        window->display();
    }

    delete window;
}
