#include "MapRenderer.h"

MapRenderer::MapRenderer(GameState *state):
        Renderer(state)
{
    if (!texture.loadFromFile("../assets/images/maps/town/sand.jpg"))
    {
        std::cout << "ERROR WITH TEXTURE" << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(state->map.initialX, state->map.initialY, 1280, 720));
}

void MapRenderer::draw(sf::RenderWindow *window)
{
    sprite.setTextureRect(sf::IntRect(state->map.initialX + state->map.offsetX,
                                      state->map.initialY + state->map.offsetY,
                                      1280,
                                      720));

    window->draw(sprite);
}
