#include "MapRenderer.h"

MapRenderer::MapRenderer(GameState *state):
        Renderer(state)
{
    if (!texture.loadFromFile("../assets/images/maps/town/sand.jpg"))
    {
        std::cout << "ERROR WITH TEXTURE" << std::endl;
    }

    sprite.setTexture(texture);
    updateView();
}

void MapRenderer::draw(sf::RenderWindow *window)
{
    updateView();

    window->draw(sprite);
}

void MapRenderer::updateView()
{
    int x = state->map.x - state->config.width / 2;
    int y = state->map.y - state->config.height / 2;

    sprite.setTextureRect(sf::IntRect(x, y, state->config.width, state->config.height));
}