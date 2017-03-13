#ifndef SFMLDEMO_GAMECOMPONENT_H
#define SFMLDEMO_GAMECOMPONENT_H

#include <SFML/Graphics/RenderWindow.hpp>

class GameComponent
{
public:
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow *window) = 0;
};

#endif //SFMLDEMO_GAMECOMPONENT_H
