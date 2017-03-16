#include "CharacterRenderer.h"
#include "../../../core/Engine.h"

CharacterRenderer::CharacterRenderer(CharacterGraphics *graphics):
        m_graphics(graphics), m_box(sf::Vector2f(graphics->boxWidth(), graphics->legRoom())),
        m_point(sf::Vector2f(1, 1))
{
    m_box.setFillColor(sf::Color(0, 255, 0, 100));
    m_point.setFillColor(sf::Color::White);
}

void CharacterRenderer::draw(sf::RenderWindow *window)
{
    updateSprite();

    window->draw(m_graphics->sprite());

    // temp and debug
    window->draw(m_point);
    window->draw(m_box);
}

void CharacterRenderer::updateSprite()
{
    m_graphics->sprite().setTextureRect(sf::IntRect(m_graphics->spriteOffsetX(), m_graphics->spriteOffsetY(),
                                      m_graphics->spriteWidth(), m_graphics->spriteHeight()));
    m_graphics->sprite().setPosition(sf::Vector2f(Engine::CX - m_graphics->spriteWidth() / 2, Engine::CY - m_graphics->boxHeight()));

    // temp and debug
    m_point.setPosition(sf::Vector2f(Engine::CX, Engine::CY));
    m_box.setPosition(sf::Vector2f(Engine::CX - m_graphics->boxWidth() / 2, Engine::CY - m_graphics->legRoom()));
}