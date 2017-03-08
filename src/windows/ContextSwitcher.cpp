#include "ContextSwitcher.h"
#include "../maps/town/Town.h"

ContextSwitcher::ContextSwitcher(Actions *actions)
{
    context = new Town(actions);
}

ContextSwitcher::~ContextSwitcher()
{
    delete context;
}

void ContextSwitcher::update()
{
    context->update();
}

void ContextSwitcher::draw(sf::RenderWindow *window)
{
    context->draw(window);
}
