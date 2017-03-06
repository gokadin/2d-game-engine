#include "MainMenu.h"

MainMenu::MainMenu() {}

MainMenu::~MainMenu() {}

void MainMenu::draw(sf::RenderWindow *window)
{
    sf::CircleShape shape(50);

    shape.setFillColor(sf::Color(100, 250, 50));

    window->draw(shape);
}