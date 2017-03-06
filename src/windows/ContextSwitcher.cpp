#include "ContextSwitcher.h"

ContextSwitcher::ContextSwitcher()
{
    context = new MainMenu();
}

ContextSwitcher::~ContextSwitcher()
{
    delete context;
}

void ContextSwitcher::draw(sf::RenderWindow *window)
{
    context->draw(window);
}
