#include "MapRenderer.h"
#include "../../../core/Engine.h"

MapRenderer::MapRenderer(MapGraphics *graphics, MapState *state, MapBounds *data):
        m_graphics(graphics), m_state(state), m_data(data), x(false), square(sf::Vector2f(16, 16)),
        boundSq(sf::Vector2f(16, 16))
{
    square.setFillColor(sf::Color(255, 0, 0, 100));
}

void MapRenderer::draw(sf::RenderWindow *window)
{
    updateView();

    window->draw(m_graphics->sprite());

//    for (int i = 0; i < m_data->bounds().size(); i++)
//    {
//        for (int j = 0; j < m_data->bounds()[i].size(); j++)
//        {
//            if (m_data->bounds()[i][j] > 0)
//            {
//                square.setPosition(i * 16 - m_state->x(), j * 16 - m_state->y());
//
//                window->draw(square);
//            }
//        }
//    }

//    int boundI = (int)((m_state->cx() - 32) / m_graphics->tileRadius()) - 1;
//    int boundJ = (int)((m_state->cy() + 32) / m_graphics->tileRadius());
//
//    boundSq.setFillColor(sf::Color(255, 255, 255, 100));
//    if (m_data->bounds()[boundI][boundJ] > 0)
//    {
//        boundSq.setFillColor(sf::Color(0, 255, 0, 150));
//    }
//    boundSq.setPosition(Engine::CX - 32 - 16, Engine::CY + 32);
//    window->draw(boundSq);
//
//    for (int i = 0; i < 4; i++)
//    {
//        // top
//        if (m_data->bounds()[boundI + i][boundJ - 1] == 0)
//        {
//            boundSq.setFillColor(sf::Color(255, 255, 255, 100));
//        }
//        else if (m_data->bounds()[boundI + i][boundJ - 1] > 0)
//        {
//            boundSq.setFillColor(sf::Color(0, 0, 0, 100));
//        }
//
//        boundSq.setPosition(Engine::CX - 32 + i * 16, Engine::CY - 32 - 16);
//
//        window->draw(boundSq);
//
//        // left
//        if (m_data->bounds()[boundI - 1][boundJ + i] == 0)
//        {
//            boundSq.setFillColor(sf::Color(255, 255, 255, 100));
//        }
//        else if (m_data->bounds()[boundI - 1][boundJ + i] > 0)
//        {
//            boundSq.setFillColor(sf::Color(0, 0, 0, 100));
//        }
//
//        boundSq.setPosition(Engine::CX - 32 - 16, Engine::CY - 32 + i * 16);
//
//        window->draw(boundSq);
//
//        // right
//        if (m_data->bounds()[boundI + 5][boundJ + i + 1] == 0)
//        {
//            boundSq.setFillColor(sf::Color(255, 255, 255, 100));
//        }
//        else if (m_data->bounds()[boundI + 5][boundJ + i] > 0)
//        {
//            boundSq.setFillColor(sf::Color(0, 0, 0, 100));
//        }
//
//        boundSq.setPosition(Engine::CX - 32 + 16 * 4, Engine::CY - 32 + i * 16);
//
//        window->draw(boundSq);
//
//        // bottom
//        if (m_data->bounds()[boundI + i][boundJ + 5] == 0)
//        {
//            boundSq.setFillColor(sf::Color(255, 255, 255, 100));
//        }
//        else if (m_data->bounds()[boundI + i][boundJ + 5] > 0)
//        {
//            boundSq.setFillColor(sf::Color(0, 0, 0, 100));
//        }
//
//        boundSq.setPosition(Engine::CX - 32 + 16 * i, Engine::CY - 32 + 4 * 16);
//
//        window->draw(boundSq);
//    }
}

void MapRenderer::updateView()
{
    m_graphics->sprite().setTextureRect(sf::IntRect((int)m_state->x(), (int)m_state->y(), Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT));
}