#include <SFML/Window/Mouse.hpp>
#include "MapUpdater.h"
#include "../../core/Engine.h"

MapUpdater::MapUpdater(sf::RenderWindow *window, MapGraphics *graphics, MapState *state, MapData *data,
                       CharacterStats *characterStats, CharacterGraphics *characterGraphics):
        m_window(window), m_graphics(graphics), m_state(state), m_data(data), m_bounds(data->bounds()),
        m_characterStats(characterStats), m_characterGraphics(characterGraphics), m_lastAngle(0.0)
{}

void MapUpdater::update()
{
    updateMovement();
}

void MapUpdater::updateMovement()
{
    if (!m_state->isMoving())
    {
        return;
    }

    if (m_state->shouldStopOnPoint())
    {
        if (m_state->x() >= m_state->lastPointX() - DESTINATION_ARRIVAL_RADIUS &&
                m_state->x() <= m_state->lastPointX() + DESTINATION_ARRIVAL_RADIUS &&
                m_state->y() >= m_state->lastPointY() - DESTINATION_ARRIVAL_RADIUS &&
                m_state->y() <= m_state->lastPointY() + DESTINATION_ARRIVAL_RADIUS)
        {
            m_state->stopMoving();

            return;
        }
    }
    else
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*m_window);
        int diffX = mousePos.x - Engine::CX;
        int diffY = mousePos.y - Engine::CY;
        m_lastAngle = atan2((double)diffY, (double)diffX);
    }

    float newX = (m_state->x() + m_characterStats->moveSpeed() * (float)cos(m_lastAngle));
    float newY = (m_state->y() + m_characterStats->moveSpeed() * (float)sin(m_lastAngle));
    float newCX = newX + Engine::HALF_SCREEN_WIDTH;
    float newCY = newY + Engine::HALF_SCREEN_HEIGHT;

    // ****
    // NEW APPROACH
    // ****
    // find quadrant
    int quadrant = m_lastAngle > 0
                   ? m_lastAngle > HALF_PI ? 3 : 4
                   : m_lastAngle > -HALF_PI ? 1 : 2;

    // check 3 sides per quadrant
    // detect if straight or diagonal collision
    // then you know...
    // don't forget no slide zone

//    int boundI = (int)((newCX + (m_lastAngle < 0
//                                 ? -m_characterGraphics->collisionRadius()
//                                 : m_characterGraphics->collisionRadius()))
//                       / m_graphics->tileRadius());
//    int boundJ = (int)((newCY + (m_lastAngle > HALF_PI && m_lastAngle < -HALF_PI
//                                 ? -m_characterGraphics->collisionRadius()
//                                 : m_characterGraphics->collisionRadius()))
//                       / m_graphics->tileRadius());

    switch (quadrant)
    {
        case 1:
        {
            int sqPerRow = m_characterGraphics->collisionRadius() * 2 / m_graphics->tileRadius();
            int boundI = (int)((m_state->cx() - m_characterGraphics->collisionRadius()) / m_graphics->tileRadius());
            int boundJ = (int)((m_state->cy() - m_characterGraphics->collisionRadius()) / m_graphics->tileRadius());
            bool goRight = false;
            bool goTop = false;
            bool goTopRight = false;
            bool goTopLeft = false;
            bool goBotRight = false;

//            std::cout << m_bounds[boundI][boundJ] << m_bounds[boundI + 1][boundJ] << m_bounds[boundI + 2][boundJ] <<
//                      m_bounds[boundI + 3][boundJ] << std::endl;
//            std::cout << m_bounds[boundI + 4][boundJ + 1] << std::endl << m_bounds[boundI + 4][boundJ + 2] <<
//                      std::endl << m_bounds[boundI + 4][boundJ + 3] << std::endl <<
//                      m_bounds[boundI + 4][boundJ + 4] << std::endl << std::endl;

            for (int i = 0; i < sqPerRow; i++)
            {
                if (m_bounds[boundI + i][boundJ] == 1)
                {
                    goRight = true;
                }
                else if (m_bounds[boundI + i][boundJ] == 2)
                {
                    if (i == 0 || i == 1)
                    {
                        goTopRight = true;
                    }
                    else if (i == sqPerRow - 1)
                    {
                        if (m_lastAngle < -QUARTER_PI)
                        {
                            goTopLeft = true;
                        }
                        else
                        {
                            goBotRight = true;
                        }
                    }
                    else
                    {
                        goRight = true;
                    }
                }

                if (m_bounds[boundI + sqPerRow][boundJ + i + 1] == 1)
                {
                    goTop = true;
                }
                else if (m_bounds[boundI + sqPerRow][boundJ + i + 1] == 2)
                {
                    if (i == 0 || i == 1)
                    {
                        if (m_lastAngle < -QUARTER_PI)
                        {
                            goTopLeft = true;
                        }
                        else
                        {
                            goBotRight = true;
                        }
                    }
                    else if (i == sqPerRow - 1)
                    {
                        goTopRight = true;
                    }
                    else
                    {
                        goTop = true;
                    }
                }
            }

            if (!goRight && !goTop && !goBotRight && !goTopLeft && !goTopRight)
            {
                m_state->setX(newX);
                m_state->setY(newY);
            }
            else if (goBotRight && !goTopRight)
            {
                m_state->setX(m_state->x() + m_characterStats->moveSpeed() / 2);
                m_state->setY(m_state->y() + m_characterStats->moveSpeed() / 2);
            }
            else if (goTopLeft && !goTopRight)
            {
                m_state->setX(m_state->x() - m_characterStats->moveSpeed() / 2);
                m_state->setY(m_state->y() - m_characterStats->moveSpeed() / 2);
            }
            else if (goTopRight)
            {
                if (m_lastAngle > -QUARTER_PI)
                {
                    m_state->setX(newX);
                    m_state->setY(newY);
                }
                else
                {
                    m_state->setX(m_state->x() + m_characterStats->moveSpeed() / 2);
                    m_state->setY(m_state->y() - m_characterStats->moveSpeed() / 2);
                }
            }
            else if (goTop && !goRight)
            {
                m_state->setY(m_state->y() - m_characterStats->moveSpeed() / 2);
            }
            else if (goRight && !goTop)
            {
                m_state->setX(m_state->x() + m_characterStats->moveSpeed() / 2);
            }
        }
            break;
        case 2:
        {
            int sqPerRow = m_characterGraphics->collisionRadius() * 2 / m_graphics->tileRadius();
            int boundI = (int)((m_state->cx() - m_characterGraphics->collisionRadius()) / m_graphics->tileRadius());
            int boundJ = (int)((m_state->cy() - m_characterGraphics->collisionRadius()) / m_graphics->tileRadius());
            bool goRight = false;
            bool goTop = false;
            bool goTopRight = false;
            bool goTopLeft = false;
            bool goBotRight = false;

//            std::cout << m_bounds[boundI][boundJ] << m_bounds[boundI + 1][boundJ] << m_bounds[boundI + 2][boundJ] <<
//                      m_bounds[boundI + 3][boundJ] << std::endl;
//            std::cout << m_bounds[boundI + 4][boundJ + 1] << std::endl << m_bounds[boundI + 4][boundJ + 2] <<
//                      std::endl << m_bounds[boundI + 4][boundJ + 3] << std::endl <<
//                      m_bounds[boundI + 4][boundJ + 4] << std::endl << std::endl;

            for (int i = 0; i < sqPerRow; i++)
            {
                if (m_bounds[boundI + sqPerRow - i - 1][boundJ] == 1)
                {
                    goRight = true;
                }
                else if (m_bounds[boundI + sqPerRow - i - 1][boundJ] == 2)
                {
                    if (i == 0 || i == 1)
                    {
                        goTopRight = true;
                    }
                    else if (i == sqPerRow - 1)
                    {
                        if (m_lastAngle < -QUARTER_PI - HALF_PI)
                        {
                            goTopLeft = true;
                        }
                        else
                        {
                            goBotRight = true;
                        }
                    }
                    else
                    {
                        goRight = true;
                    }
                }

                if (m_bounds[boundI + sqPerRow][boundJ + i + 1] == 1)
                {
                    goTop = true;
                }
                else if (m_bounds[boundI + sqPerRow][boundJ + i + 1] == 2)
                {
                    if (i == 0 || i == 1)
                    {
                        if (m_lastAngle < -QUARTER_PI - HALF_PI)
                        {
                            goTopLeft = true;
                        }
                        else
                        {
                            goBotRight = true;
                        }
                    }
                    else if (i == sqPerRow - 1)
                    {
                        goTopRight = true;
                    }
                    else
                    {
                        goTop = true;
                    }
                }
            }

            if (!goRight && !goTop && !goBotRight && !goTopLeft && !goTopRight)
            {
                m_state->setX(newX);
                m_state->setY(newY);
            }
            else if (goBotRight && !goTopRight)
            {
                m_state->setX(m_state->x() + m_characterStats->moveSpeed() / 2);
                m_state->setY(m_state->y() - m_characterStats->moveSpeed() / 2);
            }
            else if (goTopLeft && !goTopRight)
            {
                m_state->setX(m_state->x() - m_characterStats->moveSpeed() / 2);
                m_state->setY(m_state->y() + m_characterStats->moveSpeed() / 2);
            }
            else if (goTopRight)
            {
                if (m_lastAngle > -QUARTER_PI - HALF_PI)
                {
                    m_state->setX(newX);
                    m_state->setY(newY);
                }
                else
                {
                    m_state->setX(m_state->x() - m_characterStats->moveSpeed() / 2);
                    m_state->setY(m_state->y() - m_characterStats->moveSpeed() / 2);
                }
            }
            else if (goTop && !goRight)
            {
                m_state->setY(m_state->y() - m_characterStats->moveSpeed() / 2);
            }
            else if (goRight && !goTop)
            {
                m_state->setX(m_state->x() - m_characterStats->moveSpeed() / 2);
            }
        }
            break;
        case 3:
        {
            m_state->setX(newX);
            m_state->setY(newY);
        }
            break;
        case 4:
        {
            m_state->setX(newX);
            m_state->setY(newY);
        }
            break;
    }
}