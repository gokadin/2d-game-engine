#ifndef SFMLDEMO_MAPUPDATER_H
#define SFMLDEMO_MAPUPDATER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../Updater.h"
#include "../../data/definitions/map/MapGraphics.h"
#include "../../data/definitions/map/MapState.h"
#include "../../data/definitions/character/CharacterStats.h"
#include "../../data/definitions/map/MapBounds.h"
#include "../../data/definitions/character/CharacterGraphics.h"
#include "../../data/definitions/character/CharacterState.h"
#include "../../physics/collisions/CollisionProcessor.h"

class MapUpdater : public Updater
{
public:
    MapUpdater(sf::RenderWindow *window, MapGraphics *graphics, MapState *state, MapBounds *bounds,
               CharacterStats *characterStats, CharacterGraphics *characterGraphics,
               CharacterState *characterState);

    void update();

private:
    CollisionProcessor m_collisionProcessor;
    sf::RenderWindow *m_window;
    MapGraphics *m_graphics;
    MapState *m_state;
    MapBounds *m_bounds;
    CharacterStats *m_characterStats;
    CharacterGraphics *m_characterGraphics;
    CharacterState *m_characterState;
    double m_lastAngle;
    float m_lastX;
    float m_lastY;
    sf::Vector2i m_tileToReach;
    sf::Vector2f m_collisionVector;

    void updateMovement();
    void updateTileToReach(int mouseIsoX, int mouseIsoY);
    void updateMoveAngle(int mouseX, int mouseY);
    void updateDirection();

    // temp
    int bottomRightValue();
    int bottomLeftValue();
    int topRightValue();
    int topLeftValue();
};

#endif //SFMLDEMO_MAPUPDATER_H
