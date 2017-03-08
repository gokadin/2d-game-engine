#ifndef SFMLDEMO_WINDOW_H
#define SFMLDEMO_WINDOW_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class Context
{
public:
    Context();
    virtual ~Context();

    virtual void update() = 0;
    virtual void draw(sf::RenderWindow *window) = 0;
};

#endif //SFMLDEMO_WINDOW_H
