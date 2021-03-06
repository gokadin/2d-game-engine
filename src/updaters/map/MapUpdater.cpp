#include <SFML/Window/Mouse.hpp>
#include "MapUpdater.h"
#include "../../utils/math/Coords.h"
#include "../../components/map/Map.h"
#include "../../utils/math/Directions.h"

MapUpdater::MapUpdater(sf::RenderWindow *window, MapGraphics *graphics, MapState *state, MapBounds *bounds,
                       CharacterStats *characterStats, CharacterGraphics *characterGraphics,
                       CharacterState *characterState)
        : m_collisionProcessor(bounds, state, graphics), m_window(window), m_graphics(graphics), m_state(state),
          m_bounds(bounds), m_characterStats(characterStats), m_characterGraphics(characterGraphics),
          m_characterState(characterState), m_lastAngle(0.0), m_lastX(0.0f), m_lastY(0.0f), m_tileToReach(0, 0),
          m_collisionVector(0.0f, 0.0f)
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
        Coords::fromIsometric(mapPos, -m_state->isometricOffsetX(), 0);
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
        Coords::fromIsometric(mousePos, m_state->x() - m_state->isometricOffsetX(), m_state->y());
        updateTileToReach(mousePos.x, mousePos.y);
    }

    m_collisionVector.x = (float)cos(m_lastAngle);
    m_collisionVector.y = (float)sin(m_lastAngle);
    m_collisionProcessor.processMovingTile(Engine::HALF_SCREEN_WIDTH, Engine::HALF_SCREEN_HEIGHT, NODE_SIZE * 4,
                                           m_lastAngle, m_collisionVector);
    m_state->setX(m_state->x() + m_characterStats->moveSpeed() * m_collisionVector.x);
    m_state->setY(m_state->y() + m_characterStats->moveSpeed() * m_collisionVector.y);
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
    m_characterState->setDirection(Directions::directionFromAngle(m_lastAngle));
}
