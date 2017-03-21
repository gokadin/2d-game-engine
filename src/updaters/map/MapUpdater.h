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

#define HALF_PI (M_PI / 2)
#define QUARTER_PI (HALF_PI / 2)
#define THREE_QUARTER_PI (M_PI - QUARTER_PI)

class MapUpdater : public Updater
{
public:
    MapUpdater(sf::RenderWindow *window, MapGraphics *graphics, MapState *state, MapBounds *bounds,
               CharacterStats *characterStats, CharacterGraphics *characterGraphics,
               CharacterState *characterState);

    void update();

private:
    const int DESTINATION_ARRIVAL_RADIUS = 2;

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
    int m_tilesPerCharacterRow;

    void updateMovement();
    bool processFirstQuadrantCollisions();
    bool processSecondQuadrantCollisions();
    bool processThirdQuadrantCollisions();
    bool processFourthQuadrantCollisions();
};

#endif //SFMLDEMO_MAPUPDATER_H
