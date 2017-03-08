#ifndef SFMLDEMO_CONTEXT_H
#define SFMLDEMO_CONTEXT_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "Context.h"
#include "MainMenu.h"
#include "../core/Actions.h"

class ContextSwitcher
{
public:
    ContextSwitcher(Actions *actions);
    ~ContextSwitcher();

    void update();
    void draw(sf::RenderWindow *window);

private:
    Context *context;
};

#endif //SFMLDEMO_CONTEXT_H
