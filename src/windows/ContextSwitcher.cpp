#include "ContextSwitcher.h"
#include "../maps/town/Town.h"

ContextSwitcher::ContextSwitcher(Actions *actions, GameState *gameState):
        gameState(gameState)
{
    context = new Town(actions, gameState->getMapState());
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
