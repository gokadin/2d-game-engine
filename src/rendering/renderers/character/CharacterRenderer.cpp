#include "CharacterRenderer.h"
#include "../../../core/Engine.h"

CharacterRenderer::CharacterRenderer(CharacterGraphics *graphics, SortedRenderer *sortedRenderer):
        m_graphics(graphics), m_sortedRenderer(sortedRenderer), m_point(sf::Vector2f(3, 3)), m_box(sf::Vector2f(64, 64))
{
    m_box.setFillColor(sf::Color(0, 0, 255, 100));
    m_point.setFillColor(sf::Color::Red);

    SortedRenderGroup *renderGroup = new SortedRenderGroup();
    renderGroup->addDrawable(&m_box);
    renderGroup->addDrawable(&m_point);
    renderGroup->addDrawable(&m_graphics->sprite());
    m_sortedRenderer->addChar(renderGroup);
}

void CharacterRenderer::draw(sf::RenderWindow *window)
{
    updateSprite();

    //window->draw(m_graphics->sprite());

    // temp and debug
    //window->draw(m_box);
    //window->draw(m_point);
}

void CharacterRenderer::updateSprite()
{
    m_graphics->sprite().setTextureRect(sf::IntRect(m_graphics->spriteOffsetX(), m_graphics->spriteOffsetY(),
                                      m_graphics->spriteWidth(), m_graphics->spriteHeight()));
    m_graphics->sprite().setPosition(sf::Vector2f(Engine::CX - m_graphics->spriteWidth() / 2,
                                                  Engine::CY - m_graphics->hitBoxHeight()));

    // temp and debug
    m_point.setPosition(sf::Vector2f(Engine::CX - 1, Engine::CY - 1));

    m_box.setPosition(sf::Vector2f(Engine::CX - m_graphics->collisionRadius(),
                                   Engine::CY - m_graphics->collisionRadius()));
}