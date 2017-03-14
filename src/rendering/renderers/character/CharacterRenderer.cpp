#include "CharacterRenderer.h"
#include "../../../core/Engine.h"
#include <SFML/Graphics/RectangleShape.hpp>

CharacterRenderer::CharacterRenderer(CharacterGraphics *graphics):
        m_graphics(graphics)
{}

void CharacterRenderer::draw(sf::RenderWindow *window)
{
    updateSprite();

    window->draw(m_graphics->sprite());

    sf::RectangleShape rect(sf::Vector2f(5, 5));
    rect.setPosition(sf::Vector2f(Engine::CX, Engine::CY));
    window->draw(rect);
}

void CharacterRenderer::updateSprite()
{
    m_graphics->sprite().setTextureRect(sf::IntRect(m_graphics->spriteOffsetX(), m_graphics->spriteOffsetY(),
                                      m_graphics->spriteWidth(), m_graphics->spriteHeight()));
    m_graphics->sprite().setPosition(sf::Vector2f(Engine::CX - m_graphics->spriteWidth() / 2, Engine::CY - m_graphics->boxHeight()));
}