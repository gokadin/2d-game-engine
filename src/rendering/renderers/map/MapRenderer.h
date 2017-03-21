#ifndef SFMLDEMO_MAPRENDERER_H
#define SFMLDEMO_MAPRENDERER_H

#include "../../Renderer.h"
#include "../../../data/definitions/map/MapGraphics.h"
#include "../../../data/definitions/map/MapState.h"
#include "../../../data/definitions/map/MapBounds.h"

class MapRenderer : public Renderer
{
public:
    MapRenderer(MapGraphics *graphics, MapState *state, MapBounds *data);

    void draw(sf::RenderWindow *window);

private:
    MapGraphics *m_graphics;
    MapState *m_state;
    MapBounds *m_data;
    sf::RectangleShape square;
    sf::RectangleShape boundSq;
    bool x;

    void updateView();
};

#endif //SFMLDEMO_MAPRENDERER_H
