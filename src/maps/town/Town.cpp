#include "Town.h"

Town::Town() {}

Town::~Town() {}

void Town::draw(sf::RenderWindow *window)
{
    sf::CircleShape shape(50);

    shape.setFillColor(sf::Color(200, 250, 50));

    window->draw(shape);
}
