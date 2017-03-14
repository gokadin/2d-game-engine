#include "MapRenderer.h"
#include "../../../core/Engine.h"

MapRenderer::MapRenderer(MapGraphics *graphics, MapState *state):
        m_graphics(graphics), m_state(state)
{}

void MapRenderer::draw(sf::RenderWindow *window)
{
    updateView();

    window->draw(m_graphics->sprite());
}

void MapRenderer::updateView()
{
    m_graphics->sprite().setTextureRect(sf::IntRect(m_state->x(), m_state->y(), Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT));
}