#ifndef SFMLDEMO_MAPRENDERER_H
#define SFMLDEMO_MAPRENDERER_H

#include "../../Renderer.h"
#include "../../../data/definitions/map/MapGraphics.h"
#include "../../../data/definitions/map/MapState.h"

class MapRenderer : public Renderer
{
public:
    MapRenderer(MapGraphics *graphics, MapState *state);

    void draw(sf::RenderWindow *window);

private:
    MapGraphics *m_graphics;
    MapState *m_state;

    void updateView();
};

#endif //SFMLDEMO_MAPRENDERER_H
