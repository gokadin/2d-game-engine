#include <SFML/Window/Mouse.hpp>
#include "MapUpdater.h"
#include "../../utils/math/Coords.h"
#include "../../components/map/Map.h"

MapUpdater::MapUpdater(sf::RenderWindow *window, MapGraphics *graphics, MapState *state, MapBounds *bounds,
                       CharacterStats *characterStats, CharacterGraphics *characterGraphics,
                       CharacterState *characterState)
        : m_collisionProcessor(bounds), m_window(window), m_graphics(graphics), m_state(state), m_bounds(bounds),
          m_characterStats(characterStats), m_characterGraphics(characterGraphics), m_characterState(characterState),
          m_lastAngle(0.0), m_lastX(0.0f), m_lastY(0.0f), m_tileToReach(0, 0)
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

    if (m_characterState->shouldStopOnPoint())
    {
        sf::Vector2f mapPos(m_state->cx(), m_state->cy());
        Coords::fromIsometric(mapPos, -m_graphics->isometricOffsetX(), 0);
        if ((int)mapPos.x / NODE_SIZE == m_tileToReach.x && (int)mapPos.y / NODE_SIZE == m_tileToReach.y)
        {
            m_characterState->stopMoving();
            return;
        }
    }
    else
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*m_window);
        updateMoveAngle(mousePos.x, mousePos.y);
        updateDirection();
        Coords::fromIsometric(mousePos, m_state->x() - m_graphics->isometricOffsetX(), m_state->y());
        updateTileToReach(mousePos.x, mousePos.y);
    }

    float newX = (m_state->x() + m_characterStats->moveSpeed() * (float)cos(m_lastAngle));
    float newY = (m_state->y() + m_characterStats->moveSpeed() * (float)sin(m_lastAngle));
    //sf::Vector2f newPos = Coords::toIsometric(newX, newY, m_graphics->isometricOffsetX(), 0);
//    int newI = (int)newX / NODE_SIZE;
//    int newJ = (int)newY / NODE_SIZE;
//    int newI = (int)newPos.x / NODE_SIZE;
//    int newJ = (int)newPos.y / NODE_SIZE;

//    sf::Vector2f mapPos(m_state->cx(), m_state->cy());
//    Coords::fromIsometric(mapPos, -m_graphics->isometricOffsetX(), 0);

    bool temp = true;
    if (m_lastAngle >= THREE_QUARTER_PI || m_lastAngle <= -THREE_QUARTER_PI)
    {
        // left
    }
    else if (m_lastAngle >= QUARTER_PI && (bottomRightValue() > 0 || bottomLeftValue() > 0))
    {
        temp = false;

        if (bottomRightValue() == 0)
        {
            std::cout << "RIGHT FREE" << std::endl;
            m_state->setX(m_state->x() + m_characterStats->moveSpeed() / 2); // stopped here...
            m_state->setY(m_state->y() + m_characterStats->moveSpeed() / 2); // need to find perfect ratio to go smoothly along the wall
        }
        else if (bottomLeftValue() == 0)
        {
            std::cout << "LEFT FREE" << std::endl;
            m_state->setX(m_state->x() - m_characterStats->moveSpeed() * (float)cos(THREE_QUARTER_PI));
            m_state->setY(m_state->y() + m_characterStats->moveSpeed() * (float)sin(THREE_QUARTER_PI));
        }
    }
    else if (m_lastAngle <= -QUARTER_PI)
    {
        // up
    }
    else
    {
        // right
    }

    if (!temp)
    {
        return;
    }

    m_state->setX(newX);
    m_state->setY(newY);
}

void MapUpdater::updateMoveAngle(int mouseX, int mouseY)
{
    int lastDiffX = mouseX - Engine::HALF_SCREEN_WIDTH;
    int lastDiffY = mouseY - Engine::HALF_SCREEN_HEIGHT;
    m_lastAngle = atan2((double)lastDiffY, (double)lastDiffX);
}

void MapUpdater::updateTileToReach(int mouseIsoX, int mouseIsoY)
{
    m_tileToReach.x = (int)floor(mouseIsoX / NODE_SIZE);
    m_tileToReach.y = (int)floor(mouseIsoY / NODE_SIZE);
}

void MapUpdater::updateDirection()
{
    if (m_lastAngle >= FIVE_SIXTH_PI || m_lastAngle <= -FIVE_SIXTH_PI)
    {
        m_characterState->setDirection(entity_direction::LEFT);
        return;
    }

    if (m_lastAngle >= TWO_THIRDS_PI)
    {
        m_characterState->setDirection(entity_direction::DOWN_LEFT);
        return;
    }

    if (m_lastAngle >= ONE_THIRD_PI)
    {
        m_characterState->setDirection(entity_direction::DOWN);
        return;
    }

    if (m_lastAngle >= ONE_SIXTH_PI)
    {
        m_characterState->setDirection(entity_direction::DOWN_RIGHT);
        return;
    }

    if (m_lastAngle <= -TWO_THIRDS_PI)
    {
        m_characterState->setDirection(entity_direction::UP_LEFT);
        return;
    }

    if (m_lastAngle <= -ONE_THIRD_PI)
    {
        m_characterState->setDirection(entity_direction::UP);
        return;
    }

    if (m_lastAngle <= -ONE_SIXTH_PI)
    {
        m_characterState->setDirection(entity_direction::UP_RIGHT);
        return;
    }

    m_characterState->setDirection(entity_direction::DOWN_LEFT);
}

int MapUpdater::bottomRightValue()
{
    sf::Vector2i coordsDRB(Engine::HALF_SCREEN_WIDTH + 4, Engine::HALF_SCREEN_HEIGHT + NODE_SIZE);
    Coords::fromIsometric(coordsDRB, m_state->x() - m_graphics->isometricOffsetX(), m_state->y());
    coordsDRB.x /= NODE_SIZE;
    coordsDRB.y /= NODE_SIZE;

    sf::Vector2i coordsDRT(Engine::HALF_SCREEN_WIDTH + NODE_SIZE * 2, Engine::HALF_SCREEN_HEIGHT + 4);
    Coords::fromIsometric(coordsDRT, m_state->x() - m_graphics->isometricOffsetX(), m_state->y());
    coordsDRT.x /= NODE_SIZE;
    coordsDRT.y /= NODE_SIZE;

    int value = m_bounds->get(coordsDRB.x, coordsDRB.y);
    if (m_bounds->get(coordsDRT.x, coordsDRT.y) > value)
    {
        return m_bounds->get(coordsDRT.x, coordsDRT.y);
    }

    return value;
}

int MapUpdater::bottomLeftValue()
{
    sf::Vector2i coordsDLB(Engine::HALF_SCREEN_WIDTH - 4, Engine::HALF_SCREEN_HEIGHT + NODE_SIZE);
    Coords::fromIsometric(coordsDLB, m_state->x() - m_graphics->isometricOffsetX(), m_state->y());
    coordsDLB.x /= NODE_SIZE;
    coordsDLB.y /= NODE_SIZE;

    sf::Vector2i coordsDLT(Engine::HALF_SCREEN_WIDTH - NODE_SIZE * 2, Engine::HALF_SCREEN_HEIGHT + 4);
    Coords::fromIsometric(coordsDLT, m_state->x() - m_graphics->isometricOffsetX(), m_state->y());
    coordsDLT.x /= NODE_SIZE;
    coordsDLT.y /= NODE_SIZE;

    int value = m_bounds->get(coordsDLB.x, coordsDLB.y);
    if (m_bounds->get(coordsDLT.x, coordsDLT.y) > value)
    {
        return m_bounds->get(coordsDLT.x, coordsDLT.y);
    }

    return value;
}

int MapUpdater::topRightValue()
{
    sf::Vector2i coordsTRT(Engine::HALF_SCREEN_WIDTH + 4, Engine::HALF_SCREEN_HEIGHT - NODE_SIZE);
    Coords::fromIsometric(coordsTRT, m_state->x() - m_graphics->isometricOffsetX(), m_state->y());
    coordsTRT.x /= NODE_SIZE;
    coordsTRT.y /= NODE_SIZE;

    sf::Vector2i coordsTRB(Engine::HALF_SCREEN_WIDTH + NODE_SIZE * 2, Engine::HALF_SCREEN_HEIGHT - 4);
    Coords::fromIsometric(coordsTRB, m_state->x() - m_graphics->isometricOffsetX(), m_state->y());
    coordsTRB.x /= NODE_SIZE;
    coordsTRB.y /= NODE_SIZE;

    int value = m_bounds->get(coordsTRT.x, coordsTRT.y);
    if (m_bounds->get(coordsTRB.x, coordsTRB.y) > value)
    {
        return m_bounds->get(coordsTRB.x, coordsTRB.y);
    }

    return value;
}

int MapUpdater::topLeftValue()
{
    sf::Vector2i coordsTLT(Engine::HALF_SCREEN_WIDTH - 4, Engine::HALF_SCREEN_HEIGHT - NODE_SIZE);
    Coords::fromIsometric(coordsTLT, m_state->x() - m_graphics->isometricOffsetX(), m_state->y());
    coordsTLT.x /= NODE_SIZE;
    coordsTLT.y /= NODE_SIZE;

    sf::Vector2i coordsTLB(Engine::HALF_SCREEN_WIDTH - NODE_SIZE * 2, Engine::HALF_SCREEN_HEIGHT - 4);
    Coords::fromIsometric(coordsTLB, m_state->x() - m_graphics->isometricOffsetX(), m_state->y());
    coordsTLB.x /= NODE_SIZE;
    coordsTLB.y /= NODE_SIZE;

    int value = m_bounds->get(coordsTLT.x, coordsTLT.y);
    if (m_bounds->get(coordsTLB.x, coordsTLB.y) > value)
    {
        return m_bounds->get(coordsTLB.x, coordsTLB.y);
    }

    return value;
}
