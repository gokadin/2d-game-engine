#include "Engine.h"
#include "../windows/ContextSwitcher.h"
#include "Actions.h"

Engine::Engine() {}

Engine::~Engine() {}

void Engine::run()
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1280, 720), "SFML works!");

    Actions *actions = new Actions();
    ContextSwitcher *contextSwitcher = new ContextSwitcher(actions);

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

        // put in a timed loop
        // remove event argument, cause its invalid if not populated by the poll method
        contextSwitcher->update(event);

        // add fps counter
        window->clear(sf::Color::Black);
        contextSwitcher->draw(window);
        window->display();
    }

    delete actions;
    delete contextSwitcher;
    delete window;
}
