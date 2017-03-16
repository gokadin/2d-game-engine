#include "MapRenderer.h"
#include "../../../core/Engine.h"

MapRenderer::MapRenderer(MapGraphics *graphics, MapState *state, MapData *data):
        m_graphics(graphics), m_state(state), m_data(data), x(false), square(sf::Vector2f(32, 32))
{
    square.setFillColor(sf::Color(255, 0, 0, 100));
}

void MapRenderer::draw(sf::RenderWindow *window)
{
    updateView();

    window->draw(m_graphics->sprite());

    for (int i = 0; i < m_data->bounds().size() - 20; i += 32)
    {
        for (int j = 0; j < m_data->bounds()[i].size() - 20; j += 32)
        {
            if (m_data->bounds()[j][i] == 1)
            {
                square.setPosition(i - m_state->x(), j - m_state->y());

                window->draw(square);
            }
        }
    }
}

void MapRenderer::updateView()
{
    m_graphics->sprite().setTextureRect(sf::IntRect((int)m_state->x(), (int)m_state->y(), Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT));
}