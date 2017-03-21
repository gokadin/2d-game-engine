#ifndef SFMLDEMO_UIELEMENT_H
#define SFMLDEMO_UIELEMENT_H

#include <SFML/Graphics/RenderWindow.hpp>

class UIElement
{
public:
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow *window) = 0;
};

#endif //SFMLDEMO_UIELEMENT_H
