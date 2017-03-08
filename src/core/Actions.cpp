#include <iostream>
#include "Actions.h"

Actions::Actions()
{
    isMovingUp = false;
}

Actions::~Actions() {}

void Actions::update(sf::Event event)
{
    switch (event.type)
    {
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::W)
            {
                if (!isMovingUp)
                {
                    isMovingUp = true;
                    notifyObservers(new Event("mu"));
                }
            }
            break;
        case sf::Event::KeyReleased:
            if (event.key.code == sf::Keyboard::W)
            {
                isMovingUp = false;
                notifyObservers(new Event("st"));
            }
            break;
    }
}