#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "CharacterRenderer.h"

CharacterRenderer::CharacterRenderer(GameState *state):
        Renderer(state)
{}

void CharacterRenderer::draw(sf::RenderWindow *window)
{
    sf::RectangleShape rect(sf::Vector2f(state->character.boxWidth, state->character.boxHeight));
    rect.setFillColor(sf::Color(255, 0, 0));
    rect.setPosition(sf::Vector2f(state->character.x - state->character.boxWidth, state->character.y - state->character.boxHeight));

    window->draw(rect);
}
