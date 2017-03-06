#ifndef SFMLDEMO_CONTEXT_H
#define SFMLDEMO_CONTEXT_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Context.h"
#include "MainMenu.h"

class ContextSwitcher
{
public:
    ContextSwitcher();
    ~ContextSwitcher();

    void draw(sf::RenderWindow *window);

private:
    Context *context;
};

#endif //SFMLDEMO_CONTEXT_H
