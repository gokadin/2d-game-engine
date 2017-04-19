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

#define HALF_PI (M_PI / 2)
#define QUARTER_PI (HALF_PI / 2)
#define THREE_QUARTER_PI (M_PI - QUARTER_PI)
#define ONE_SIXTH_PI (M_PI / 6)
#define ONE_THIRD_PI (M_PI / 3)
#define TWO_THIRDS_PI (ONE_THIRD_PI * 2)
#define FIVE_SIXTH_PI (ONE_SIXTH_PI * 5)

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
