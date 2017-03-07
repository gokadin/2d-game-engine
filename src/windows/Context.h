#ifndef SFMLDEMO_WINDOW_H
#define SFMLDEMO_WINDOW_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class Context
{
public:
    Context();
    virtual ~Context();

    virtual void update(sf::Event event);
    virtual void draw(sf::RenderWindow *window);
};

#endif //SFMLDEMO_WINDOW_H
