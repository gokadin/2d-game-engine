#include "Town.h"

#include <iostream>

Town::Town()
{
    if (!texture.loadFromFile("../assets/images/maps/town/sand.jpg"))
    {
        std::cout << "ERROR WITH TEXTURE" << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(100, 100, 1280, 720));
}

Town::~Town() {}

void Town::update(sf::Event event)
{
    switch (event.type)
    {
        case sf::Event::KeyPressed:
            handleKeyPressed(event.key.code);
            break;
    }
}

void Town::draw(sf::RenderWindow *window)
{
    window->draw(sprite);
}

void Town::handleKeyPressed(sf::Keyboard::Key code)
{
    switch (code)
    {
        case sf::Keyboard::W:
            handleWPressed();
            break;
    }
}

void Town::handleWPressed()
{
    sprite.setTextureRect(sf::IntRect(110, 120, 1280, 720));
}