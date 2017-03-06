#include "ContextSwitcher.h"
#include "../maps/town/Town.h"

ContextSwitcher::ContextSwitcher()
{
    context = new Town();
}

ContextSwitcher::~ContextSwitcher()
{
    delete context;
}

void ContextSwitcher::draw(sf::RenderWindow *window)
{
    context->draw(window);
}
