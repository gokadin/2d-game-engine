#include <SFML/Window/Mouse.hpp>
#include "MapUpdater.h"
#include "../../core/Engine.h"

MapUpdater::MapUpdater(sf::RenderWindow *window, MapGraphics *graphics, MapState *state, MapData *data,
                       CharacterStats *characterStats, CharacterGraphics *characterGraphics,
                       CharacterState *characterState):
        m_window(window), m_graphics(graphics), m_state(state), m_data(data), m_bounds(data->bounds()),
        m_characterStats(characterStats), m_characterGraphics(characterGraphics), m_characterState(characterState),
        m_lastAngle(0.0), m_lastX(0.0f), m_lastY(0.0f), m_tilesPerCharacterRow(0)
{}

void MapUpdater::update()
{
    updateMovement();
}

void MapUpdater::updateMovement()
{
    if (!m_characterState->isMoving() || m_characterState->isMovementPaused())
    {
        return;
    }

    m_tilesPerCharacterRow = m_characterGraphics->collisionRadius() * 2 / m_graphics->tileRadius(); //  REMOVE

    if (m_characterState->shouldStopOnPoint())
    {
        if (m_state->x() >= m_lastX - DESTINATION_ARRIVAL_RADIUS &&
                m_state->x() <= m_lastX + DESTINATION_ARRIVAL_RADIUS &&
                m_state->y() >= m_lastY - DESTINATION_ARRIVAL_RADIUS &&
                m_state->y() <= m_lastY + DESTINATION_ARRIVAL_RADIUS)
        {
            m_characterState->stopMoving();

            return;
        }
    }
    else
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*m_window);
        int lastDiffX = mousePos.x - Engine::CX;
        int lastDiffY = mousePos.y - Engine::CY;
        m_lastX = m_state->x() + lastDiffX;
        m_lastY = m_state->y() + lastDiffY;
        m_lastAngle = atan2((double)lastDiffY, (double)lastDiffX);
    }

    float newX = (m_state->x() + m_characterStats->moveSpeed() * (float)cos(m_lastAngle));
    float newY = (m_state->y() + m_characterStats->moveSpeed() * (float)sin(m_lastAngle));

    bool hasCollided;
    if (m_lastAngle > HALF_PI) // 3
    {
        hasCollided = processThirdQuadrantCollisions();
    }
    else if (m_lastAngle > 0) // 4
    {
        hasCollided = processFourthQuadrantCollisions();
    }
    else if (m_lastAngle < -HALF_PI) // 2
    {
        hasCollided = processSecondQuadrantCollisions();
    }
    else // 1
    {
        hasCollided = processFirstQuadrantCollisions();
    }

    if (!hasCollided)
    {
        m_state->setX(newX);
        m_state->setY(newY);
    }
}

bool MapUpdater::processFirstQuadrantCollisions()
{
    int boundI = (int)((m_state->cx() + m_characterGraphics->collisionRadius()) / m_graphics->tileRadius()) + 1;
    int boundJ = (int)((m_state->cy() - m_characterGraphics->collisionRadius()) / m_graphics->tileRadius()) - 1;

    // diagonal
    if (m_bounds[boundI - 1][boundJ] == 2 && m_bounds[boundI][boundJ + 1] == 2)
    {
        if (m_lastAngle < -QUARTER_PI)
        {
            // go top left
            if (m_bounds[boundI - m_tilesPerCharacterRow - 1][boundJ] == 0)
            {
                m_state->setX(m_state->x() - m_characterStats->moveSpeed() / 2);
                m_state->setY(m_state->y() - m_characterStats->moveSpeed() / 2);
            }

            return true;
        }
        else
        {
            // go bot right
            if (m_bounds[boundI][boundJ + m_tilesPerCharacterRow + 1] == 0)
            {
                m_state->setX(m_state->x() + m_characterStats->moveSpeed() / 2);
                m_state->setY(m_state->y() + m_characterStats->moveSpeed() / 2);
            }

            return true;
        }
    }

    // diagonal forward
    if ((m_bounds[boundI - m_tilesPerCharacterRow - 1][boundJ] == 2 && m_lastAngle < -QUARTER_PI) ||
            (m_bounds[boundI][boundJ + m_tilesPerCharacterRow + 1] == 2 && m_lastAngle > -QUARTER_PI))
    {
        if (m_bounds[boundI][boundJ] == 0)
        {
            m_state->setX(m_state->x() + m_characterStats->moveSpeed() / 2);
            m_state->setY(m_state->y() - m_characterStats->moveSpeed() / 2);
        }

        return true;
    }

    // right
    if (m_bounds[boundI - m_tilesPerCharacterRow - 1][boundJ] == 1 || m_bounds[boundI - 1][boundJ] == 1)
    {
        if (m_bounds[boundI][boundJ + 1] == 0 && m_bounds[boundI][boundJ + m_tilesPerCharacterRow + 1] == 0)
        {
            m_state->setX(m_state->x() + m_characterStats->moveSpeed());
        }

        return true;
    }

    // top
    if (m_bounds[boundI][boundJ + m_tilesPerCharacterRow + 1] == 1 || m_bounds[boundI][boundJ + 1] == 1)
    {
        if (m_bounds[boundI - 1][boundJ] == 0 && m_bounds[boundI - m_tilesPerCharacterRow - 1][boundJ] == 0)
        {
            m_state->setY(m_state->y() - m_characterStats->moveSpeed());
        }

        return true;
    }

    return false;
}

bool MapUpdater::processSecondQuadrantCollisions()
{
    int boundI = (int)((m_state->cx() - m_characterGraphics->collisionRadius()) / m_graphics->tileRadius()) - 1;
    int boundJ = (int)((m_state->cy() - m_characterGraphics->collisionRadius()) / m_graphics->tileRadius()) - 1;

    // diagonal
    if (m_bounds[boundI + 1][boundJ] == 2 && m_bounds[boundI][boundJ + 1] == 2)
    {
        if (m_lastAngle < -THREE_QUARTER_PI)
        {
            // go bottom left
            if (m_bounds[boundI][boundJ + m_tilesPerCharacterRow + 1] == 0)
            {
                m_state->setX(m_state->x() - m_characterStats->moveSpeed() / 2);
                m_state->setY(m_state->y() + m_characterStats->moveSpeed() / 2);
            }

            return true;
        }
        else
        {
            // go top right
            if (m_bounds[boundI + m_tilesPerCharacterRow + 1][boundJ] == 0)
            {
                m_state->setX(m_state->x() + m_characterStats->moveSpeed() / 2);
                m_state->setY(m_state->y() - m_characterStats->moveSpeed() / 2);
            }

            return true;
        }
    }

    // diagonal forward
    if ((m_bounds[boundI + m_tilesPerCharacterRow + 1][boundJ] == 2 && m_lastAngle > -THREE_QUARTER_PI) ||
        (m_bounds[boundI][boundJ + m_tilesPerCharacterRow + 1] == 2 && m_lastAngle < -QUARTER_PI))
    {
        if (m_bounds[boundI][boundJ] == 0)
        {
            m_state->setX(m_state->x() - m_characterStats->moveSpeed() / 2);
            m_state->setY(m_state->y() - m_characterStats->moveSpeed() / 2);
        }

        return true;
    }

    // left
    if (m_bounds[boundI + 1][boundJ] == 1 || m_bounds[boundI + m_tilesPerCharacterRow + 1][boundJ] == 1)
    {
        if (m_bounds[boundI][boundJ + 1] == 0 && m_bounds[boundI][boundJ + m_tilesPerCharacterRow + 1] == 0)
        {
            m_state->setX(m_state->x() - m_characterStats->moveSpeed());
        }

        return true;
    }

    // top
    if (m_bounds[boundI][boundJ + 1] == 1 || m_bounds[boundI][boundJ + m_tilesPerCharacterRow + 1] == 1)
    {
        if (m_bounds[boundI + 1][boundJ] == 0 && m_bounds[boundI + m_tilesPerCharacterRow + 1][boundJ] == 0)
        {
            m_state->setY(m_state->y() - m_characterStats->moveSpeed());
        }

        return true;
    }

    return false;
}

bool MapUpdater::processThirdQuadrantCollisions()
{
    int boundI = (int)((m_state->cx() - m_characterGraphics->collisionRadius()) / m_graphics->tileRadius()) - 1;
    int boundJ = (int)((m_state->cy() + m_characterGraphics->collisionRadius()) / m_graphics->tileRadius()) + 1;

    // diagonal
    if (m_bounds[boundI + 1][boundJ] == 2 && m_bounds[boundI][boundJ - 1] == 2)
    {
        if (m_lastAngle > THREE_QUARTER_PI)
        {
            // go top left
            if (m_bounds[boundI][boundJ - m_tilesPerCharacterRow - 1] == 0)
            {
                m_state->setX(m_state->x() - m_characterStats->moveSpeed() / 2);
                m_state->setY(m_state->y() - m_characterStats->moveSpeed() / 2);
            }

            return true;
        }
        else
        {
            // go bot right
            if (m_bounds[boundI = m_tilesPerCharacterRow + 1][boundJ] == 0)
            {
                m_state->setX(m_state->x() + m_characterStats->moveSpeed() / 2);
                m_state->setY(m_state->y() + m_characterStats->moveSpeed() / 2);
            }

            return true;
        }
    }

    // diagonal forward
    if ((m_bounds[boundI][boundJ - m_tilesPerCharacterRow - 1] == 2 && m_lastAngle > THREE_QUARTER_PI) ||
        (m_bounds[boundI + m_tilesPerCharacterRow + 1][boundJ] == 2 && m_lastAngle < THREE_QUARTER_PI))
    {
        if (m_bounds[boundI][boundJ] == 0)
        {
            m_state->setX(m_state->x() - m_characterStats->moveSpeed() / 2);
            m_state->setY(m_state->y() + m_characterStats->moveSpeed() / 2);
        }

        return true;
    }

    // left
    if (m_bounds[boundI + m_tilesPerCharacterRow + 1][boundJ] == 1 || m_bounds[boundI + 1][boundJ] == 1)
    {
        if (m_bounds[boundI][boundJ - 1] == 0 && m_bounds[boundI][boundJ - m_tilesPerCharacterRow - 1] == 0)
        {
            m_state->setX(m_state->x() - m_characterStats->moveSpeed());
        }

        return true;
    }

    // bottom
    if (m_bounds[boundI][boundJ - m_tilesPerCharacterRow - 1] == 1 || m_bounds[boundI][boundJ - 1] == 1)
    {
        if (m_bounds[boundI + 1][boundJ] == 0 && m_bounds[boundI + m_tilesPerCharacterRow + 1][boundJ] == 0)
        {
            m_state->setY(m_state->y() + m_characterStats->moveSpeed());
        }

        return true;
    }

    return false;
}

bool MapUpdater::processFourthQuadrantCollisions()
{
    int boundI = (int)((m_state->cx() + m_characterGraphics->collisionRadius()) / m_graphics->tileRadius()) + 1;
    int boundJ = (int)((m_state->cy() + m_characterGraphics->collisionRadius()) / m_graphics->tileRadius()) + 1;

    // diagonal
    if (m_bounds[boundI - 1][boundJ] == 2 && m_bounds[boundI][boundJ - 1] == 2)
    {
        if (m_lastAngle > QUARTER_PI)
        {
            // go bottom left
            if (m_bounds[boundI - m_tilesPerCharacterRow - 1][boundJ] == 0)
            {
                m_state->setX(m_state->x() - m_characterStats->moveSpeed() / 2);
                m_state->setY(m_state->y() + m_characterStats->moveSpeed() / 2);
            }

            return true;
        }
        else
        {
            // go top right
            if (m_bounds[boundI][boundJ - m_tilesPerCharacterRow - 1] == 0)
            {
                m_state->setX(m_state->x() + m_characterStats->moveSpeed() / 2);
                m_state->setY(m_state->y() - m_characterStats->moveSpeed() / 2);
            }

            return true;
        }
    }

    // diagonal forward
    if ((m_bounds[boundI - m_tilesPerCharacterRow - 1][boundJ] == 2 && m_lastAngle > QUARTER_PI) ||
        (m_bounds[boundI][boundJ - m_tilesPerCharacterRow - 1] == 2 && m_lastAngle < QUARTER_PI))
    {
        if (m_bounds[boundI][boundJ] == 0)
        {
            m_state->setX(m_state->x() + m_characterStats->moveSpeed() / 2);
            m_state->setY(m_state->y() + m_characterStats->moveSpeed() / 2);
        }

        return true;
    }

    // right
    if (m_bounds[boundI - m_tilesPerCharacterRow - 1][boundJ] == 1 || m_bounds[boundI - 1][boundJ] == 1)
    {
        if (m_bounds[boundI][boundJ - 1] == 0 && m_bounds[boundI][boundJ - m_tilesPerCharacterRow - 1] == 0)
        {
            m_state->setX(m_state->x() + m_characterStats->moveSpeed());
        }

        return true;
    }

    // bottom
    if (m_bounds[boundI][boundJ - m_tilesPerCharacterRow - 1] == 1 || m_bounds[boundI][boundJ - 1] == 1)
    {
        if (m_bounds[boundI - 1][boundJ] == 0 && m_bounds[boundI - m_tilesPerCharacterRow - 1][boundJ] == 0)
        {
            m_state->setY(m_state->y() + m_characterStats->moveSpeed());
        }

        return true;
    }

    return false;
}
