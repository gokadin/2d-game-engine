#ifndef SFMLDEMO_MAPUPDATER_H
#define SFMLDEMO_MAPUPDATER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../Updater.h"
#include "../../data/definitions/map/MapGraphics.h"
#include "../../data/definitions/map/MapState.h"

const float SPEED = 0.5; // change this

class MapUpdater : public Updater
{
public:
    MapUpdater(MapGraphics *graphics, MapState *state, sf::RenderWindow *window);

    void update();

private:
    MapGraphics *m_graphics;
    MapState *m_state;
    sf::RenderWindow *m_window;

    void updateMovement();
};

#endif //SFMLDEMO_MAPUPDATER_H
