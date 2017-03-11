#ifndef SFMLDEMO_DRAWABLE_H
#define SFMLDEMO_DRAWABLE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../states/GameState.h"

class Renderer
{
public:
    Renderer(GameState& state):
            state(state)
    {}

    virtual void draw(sf::RenderWindow *window) = 0;

protected:
    GameState& state;
};

#endif //SFMLDEMO_DRAWABLE_H
