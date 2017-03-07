#include "ContextSwitcher.h"
#include "../maps/town/Town.h"

#include <iostream>

ContextSwitcher::ContextSwitcher()
{
    context = new Town();
}

ContextSwitcher::~ContextSwitcher()
{
    delete context;
}

void ContextSwitcher::update(sf::Event event)
{
    context->update(event);
}

void ContextSwitcher::draw(sf::RenderWindow *window)
{
    context->draw(window);
}
