#include "MapRenderer.h"
#include "../../../core/Engine.h"

MapRenderer::MapRenderer(MapGraphics *graphics, MapState *state, MapBounds *data):
        m_graphics(graphics), m_state(state), m_data(data), x(false), square(sf::Vector2f(32, 16)),
        boundSq(sf::Vector2f(32, 16))
{
    square.setFillColor(sf::Color(255, 0, 0, 100));
}

void MapRenderer::draw(sf::RenderWindow *window)
{
    updateView();

    window->draw(m_graphics->sprite());

//    for (int i = 0; i < m_data->width(); i++)
//    {
//        for (int j = 0; j < m_data->height(); j++)
//        {
//            float posX = i * m_data->tileWidth() - m_state->x();
//            float posY = j * m_data->tileHeight() - m_state->y();
//
//            switch (m_data->get(i, j))
//            {
//                case 2:
//                {
//                    sf::VertexArray triangleR(sf::Triangles, 3);
//
//                    triangleR[0].position = sf::Vector2f(posX, posY);
//                    triangleR[1].position = sf::Vector2f(posX + m_data->tileWidth(), posY);
//                    triangleR[2].position = sf::Vector2f(posX, posY + m_data->tileHeight());
//
//                    triangleR[0].color = sf::Color(0, 0, 0, 200);
//                    triangleR[1].color = sf::Color(0, 0, 0, 200);
//                    triangleR[2].color = sf::Color(0, 0, 0, 200);
//
//                    window->draw(triangleR);
//                    break;
//                }
//                case 3:
//                {
//                    sf::VertexArray triangleT(sf::Triangles, 3);
//
//                    triangleT[0].position = sf::Vector2f(posX, posY);
//                    triangleT[1].position = sf::Vector2f(posX + m_data->tileWidth(),
//                                                         posY);
//                    triangleT[2].position = sf::Vector2f(posX + m_data->tileWidth(),
//                                                         posY + m_data->tileHeight());
//
//                    triangleT[0].color = sf::Color(0, 0, 0, 200);
//                    triangleT[1].color = sf::Color(0, 0, 0, 200);
//                    triangleT[2].color = sf::Color(0, 0, 0, 200);
//
//                    window->draw(triangleT);
//                    break;
//                }
//                case 4:
//                {
//                    sf::VertexArray triangleF(sf::Triangles, 3);
//
//                    triangleF[0].position = sf::Vector2f(posX, posY);
//                    triangleF[1].position = sf::Vector2f(posX + m_data->tileWidth(),
//                                                         posY + m_data->tileHeight());
//                    triangleF[2].position = sf::Vector2f(posX,
//                                                         posY + m_data->tileHeight());
//
//                    triangleF[0].color = sf::Color(0, 0, 0, 200);
//                    triangleF[1].color = sf::Color(0, 0, 0, 200);
//                    triangleF[2].color = sf::Color(0, 0, 0, 200);
//
//                    window->draw(triangleF);
//                    break;
//                }
//                case 5:
//                {
//                    sf::VertexArray triangleG(sf::Triangles, 3);
//
//                    triangleG[0].position = sf::Vector2f(posX + m_data->tileWidth(), posY);
//                    triangleG[1].position = sf::Vector2f(posX + m_data->tileWidth(),
//                                                         posY + m_data->tileHeight());
//                    triangleG[2].position = sf::Vector2f(posX,
//                                                         posY + m_data->tileHeight());
//
//                    triangleG[0].color = sf::Color(0, 0, 0, 200);
//                    triangleG[1].color = sf::Color(0, 0, 0, 200);
//                    triangleG[2].color = sf::Color(0, 0, 0, 200);
//
//                    window->draw(triangleG);
//                    break;
//                }
//                case 1:
//                {
//                    square.setFillColor(sf::Color(255, 0, 0, 100));
//                    square.setPosition(i * m_data->tileWidth() - m_state->x(), j * m_data->tileHeight() - m_state->y());
//                    window->draw(square);
//                    break;
//                }
//            }
//
//            if (m_data->get(i, j) >= 1000)
//            {
//                square.setFillColor(sf::Color(0, 255, 0, 100));
//                square.setPosition(i * m_data->tileWidth() - m_state->x(), j * m_data->tileHeight() - m_state->y());
//                window->draw(square);
//            }
//        }
//    }
}

void MapRenderer::updateView()
{
    m_graphics->sprite().setTextureRect(sf::IntRect((int)m_state->x(), (int)m_state->y(), Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT));
}