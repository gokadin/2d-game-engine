#ifndef SFMLDEMO_MAPUPDATER_H
#define SFMLDEMO_MAPUPDATER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../Updater.h"
#include "../../data/definitions/map/MapGraphics.h"
#include "../../data/definitions/map/MapState.h"
#include "../../data/definitions/character/CharacterStats.h"
#include "../../data/definitions/map/MapData.h"

class MapUpdater : public Updater
{
public:
    MapUpdater(sf::RenderWindow *window, MapGraphics *graphics, MapState *state, MapData *data,
               CharacterStats *characterStats);

    void update();

private:
    const int DESTINATION_ARRIVAL_RADIUS = 2;

    sf::RenderWindow *m_window;
    MapGraphics *m_graphics;
    MapState *m_state;
    MapData *m_data;
    CharacterStats *m_characterStats;
    double m_lastAngle;

    void updateMovement();
};

#endif //SFMLDEMO_MAPUPDATER_H
