#ifndef SFMLDEMO_DRAWABLE_H
#define SFMLDEMO_DRAWABLE_H

#include <SFML/Graphics/RenderWindow.hpp>

class Renderer
{
public:
    virtual void draw(sf::RenderWindow *window) = 0;
};

#endif //SFMLDEMO_DRAWABLE_H
