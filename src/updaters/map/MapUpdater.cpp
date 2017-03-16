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

    float newX = m_state->x() + m_characterStats->moveSpeed() * (float)cos(m_lastAngle);
    float newY = m_state->y() + m_characterStats->moveSpeed() * (float)sin(m_lastAngle);
    float newCX = newX + Engine::HALF_SCREEN_WIDTH;
    float newCY = newY + Engine::HALF_SCREEN_HEIGHT;

    // check direction first of all, then process colision detection

    if (m_bounds[newCY][newCX] == 1)
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*m_window);
        int diffX = mousePos.x - Engine::CX;
        int diffY = mousePos.y - Engine::CY;

        if (diffX > 0 && diffY < 0)
        {
            // ^>

            bool top = m_bounds[newCY][newCX - 5] == 0;
            bool right = m_bounds[newCY + 5][newCX] == 0;
            std::cout << "^> TOP: " << top << " RIGHT: " << right << std::endl;

            if (top)
                m_state->setY(m_state->y() - m_characterStats->moveSpeed());
            else if (right)
                m_state->setX(m_state->x() + m_characterStats->moveSpeed());
        }
        else if (diffX > 0 && diffY > 0)
        {
            // v>

            bool bot = m_bounds[newCY][newCX + 5] == 0;
            bool right = m_bounds[newCY + 5][newCX] == 0;
            std::cout << "v> BOT: " << bot << " RIGHT: " << right << std::endl;

            if (bot)
                m_state->setY(m_state->y() + m_characterStats->moveSpeed());
            else if (right)
                m_state->setX(m_state->x() + m_characterStats->moveSpeed());
        }
        else if (diffX < 0 && diffY > 0)
        {
            // <v

            bool bot = m_bounds[newCY][newCX + 5] == 0;
            bool left = m_bounds[newCY - 5][newCX] == 0;
            std::cout << "^v BOT: " << bot << " LEFT: " << left << std::endl;

            if (bot)
                m_state->setY(m_state->y() + m_characterStats->moveSpeed());
            else if (left)
                m_state->setX(m_state->x() - m_characterStats->moveSpeed());
        }
        else
        {
            // <^

            bool top = m_bounds[newCY][newCX - 5] == 0;
            bool left = m_bounds[newCY - 5][newCX] == 0;
            std::cout << "<^ TOP: " << top << " LEFT: " << left << std::endl;

            if (top)
                m_state->setY(m_state->y() - m_characterStats->moveSpeed());
            else if (left)
                m_state->setX(m_state->x() - m_characterStats->moveSpeed());
        }
    }
    else
    {
        m_state->setX(newX);
        m_state->setY(newY);
    }
}

//void MapUpdater::moveUp()
//{
//    if (!state.character.isMovingUp || state.character.isMovingDown)
//    {
//        return;
//    }
//
//    int charTop = state.map.cy - state.character.legRoom - state.character.moveSpeed;
//    bool leftFree = state.map.bounds[charTop][state.map.cx - state.character.boxWidth / 2] == 0;
//    bool rightFree = state.map.bounds[charTop][state.map.cx + state.character.boxWidth / 2] == 0;
//    if (!leftFree && !rightFree)
//    {
//        return;
//    }
//
//    if (leftFree && !rightFree)
//    {
//        state.map.cx -= state.character.moveSpeed;
//    }
//    else if (!leftFree)
//    {
//        state.map.cx += state.character.moveSpeed;
//    }
//
//    state.map.cy -= state.character.moveSpeed;
//}
//
//void MapUpdater::moveDown()
//{
//    if (!state.character.isMovingDown || state.character.isMovingUp)
//    {
//        return;
//    }
//
//    int charBottom = state.map.cy + state.character.moveSpeed;
//    bool leftFree = state.map.bounds[charBottom][state.map.cx - state.character.boxWidth / 2] == 0;
//    bool rightFree = state.map.bounds[charBottom][state.map.cx + state.character.boxWidth / 2] == 0;
//    if (!leftFree && !rightFree)
//    {
//        return;
//    }
//
//    if (leftFree && !rightFree)
//    {
//        state.map.cx -= state.character.moveSpeed;
//    }
//    else if (!leftFree)
//    {
//        state.map.cx += state.character.moveSpeed;
//    }
//
//    state.map.cy += state.character.moveSpeed;
//}
//
//void MapUpdater::moveRight()
//{
//    if (!state.character.isMovingRight || state.character.isMovingLeft)
//    {
//        return;
//    }
//
//    int charRight = state.map.cx + state.character.boxWidth / 2 + state.character.moveSpeed;
//    bool topFree = state.map.bounds[state.map.cy - state.character.legRoom][charRight] == 0;
//    bool bottomFree = state.map.bounds[state.map.cy][charRight] == 0;
//    if (!topFree && !bottomFree)
//    {
//        return;
//    }
//
//    if (topFree && !bottomFree)
//    {
//        state.map.cy -= state.character.moveSpeed;
//    }
//    else if (!topFree)
//    {
//        state.map.cy += state.character.moveSpeed;
//    }
//
//    state.map.cx += state.character.moveSpeed;
//}
//
//void MapUpdater::moveLeft()
//{
//    if (!state.character.isMovingLeft || state.character.isMovingRight)
//    {
//        return;
//    }
//
//    int charLeft = state.map.cx - state.character.boxWidth / 2 - state.character.moveSpeed;
//    bool topFree = state.map.bounds[state.map.cy - state.character.legRoom][charLeft] == 0;
//    bool bottomFree = state.map.bounds[state.map.cy][charLeft] == 0;
//    if (!topFree && !bottomFree)
//    {
//        return;
//    }
//
//    if (topFree && !bottomFree)
//    {
//        state.map.cy -= state.character.moveSpeed;
//    }
//    else if (!topFree)
//    {
//        state.map.cy += state.character.moveSpeed;
//    }
//
//    state.map.cx -= state.character.moveSpeed;
//}
