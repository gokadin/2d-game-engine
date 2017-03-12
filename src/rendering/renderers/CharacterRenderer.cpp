#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include "CharacterRenderer.h"

CharacterRenderer::CharacterRenderer(GameState& state):
        Renderer(state)
{
    if (!texture.loadFromFile(state.character.texture))
    {
        std::cout << "ERROR WITH TEXTURE" << std::endl;
    }

    sprite.setTexture(texture);
}

void CharacterRenderer::draw(sf::RenderWindow *window)
{
    updateSprite();

    window->draw(sprite);

    sf::RectangleShape rect(sf::Vector2f(5, 5));
    rect.setPosition(sf::Vector2f(state.config.cx, state.config.cy));
    window->draw(rect);
}

void CharacterRenderer::updateSprite()
{
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 64));
    sprite.setPosition(sf::Vector2f(state.config.cx - state.character.boxWidth / 2, state.config.cy - state.character.boxHeight));
}