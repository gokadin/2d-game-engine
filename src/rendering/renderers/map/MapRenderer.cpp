#include "MapRenderer.h"
#include "../../../components/map/Map.h"
#include "../../../utils/math/Coords.h"

MapRenderer::MapRenderer(MapGraphics *graphics, MapState *state, MapBounds *bounds)
        : m_graphics(graphics), m_state(state), m_bounds(bounds)
{
    if (!m_gridTexture.loadFromFile("../src/storage/game/maps/debug/grid_" + std::to_string(NODE_SIZE) + ".png"))
    {
        std::cout << "Could not load debug grid texture." << std::endl;
    }
    m_gridSprite.setTexture(m_gridTexture);

    if (!m_shadedGridTexture.loadFromFile("../src/storage/game/maps/debug/shadedGrid_" + std::to_string(NODE_SIZE) + ".png"))
    {
        std::cout << "Could not load debug grid texture." << std::endl;
    }
    m_shadedGridSprite.setTexture(m_shadedGridTexture);
}

void MapRenderer::update()
{
    m_graphics->sprite().setTextureRect(sf::IntRect((int)m_state->x(), (int)m_state->y(), Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT));
}

void MapRenderer::draw(sf::RenderWindow *window)
{
    window->draw(m_graphics->sprite());

    if (!DEBUG_MAP)
    {
        return;
    }

    for (int i = 0; i < m_graphics->spriteWidth() / (NODE_SIZE * 4); i++)
    {
        for (int j = 0; j < m_graphics->spriteWidth() / (NODE_SIZE * 4); j++) // change
        {
            int x = i * NODE_SIZE;
            int y = j * NODE_SIZE;
            m_gridSprite.setPosition(Coords::toIsometric(x, y, m_state->x() - m_state->isometricOffsetX() + NODE_SIZE * 2, m_state->y()));
            window->draw(m_gridSprite);

            if (m_bounds->get(i, j) > 0)
            {
                m_shadedGridSprite.setPosition(Coords::toIsometric(x, y, m_state->x() - m_state->isometricOffsetX() + NODE_SIZE * 2, m_state->y()));
                window->draw(m_shadedGridSprite);
            }
        }
    }
}
