#include "Town.h"

#include <iostream>

Town::Town(Actions *actions) : Map(actions)
{
    if (!texture.loadFromFile("../assets/images/maps/town/sand.jpg"))
    {
        std::cout << "ERROR WITH TEXTURE" << std::endl;
    }

    sprite.setTexture(texture);
    a = 0;
    b = 0;
    move = false;
    sprite.setTextureRect(sf::IntRect(a, 100, 1280, 720));
}

Town::~Town() {}

void Town::notify(Event *event)
{
    if (event->getType() == "mu")
    {
        move = true;
    }
    else if (event->getType() == "st")
    {
        move = false;
    }
}

void Town::update()
{
    if (move)
    {
        handleWPressed();
    }
}

void Town::draw(sf::RenderWindow *window)
{
    window->draw(sprite);
}

void Town::handleWPressed()
{
    b += 10;
    sprite.setTextureRect(sf::IntRect(a + b, 100, 1280, 720));
}