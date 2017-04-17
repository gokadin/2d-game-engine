#include "CharacterRenderer.h"
#include "../../../core/Engine.h"

CharacterRenderer::CharacterRenderer(CharacterGraphics *graphics):
        m_graphics(graphics), m_point(sf::Vector2f(3, 3))
{
    m_point.setFillColor(sf::Color::Red);
}

void CharacterRenderer::update()
{
    m_graphics->sprite().setTextureRect(sf::IntRect(m_graphics->spriteOffsetX(), m_graphics->spriteOffsetY(),
                                                    m_graphics->spriteWidth(), m_graphics->spriteHeight()));

    m_graphics->sprite().setPosition(sf::Vector2f(Engine::HALF_SCREEN_WIDTH - m_graphics->spriteWidth() / 2,
                                                  Engine::HALF_SCREEN_HEIGHT - m_graphics->hitBoxHeight()));

    // temp and debug
    m_point.setPosition(sf::Vector2f(Engine::HALF_SCREEN_WIDTH - 1, Engine::HALF_SCREEN_HEIGHT - 1));
}

void CharacterRenderer::draw(sf::RenderWindow *window)
{
    window->draw(m_graphics->sprite());

    // temp and debug
    window->draw(m_point);
}
