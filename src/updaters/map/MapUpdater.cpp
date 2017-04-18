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

    sf::Vector2f mapPos(m_state->cx(), m_state->cy());
    Coords::fromIsometric(mapPos, -m_graphics->isometricOffsetX(), 0);
    int newI = (int)mapPos.x / NODE_SIZE;
    int newJ = (int)mapPos.y / NODE_SIZE;

    switch (m_characterState->direction())
    {
        case entity_direction::UP:
            // write logic here and transfer to collision processor later
            break;
    }

    if (m_bounds->get(newI, newJ) > 0)
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
