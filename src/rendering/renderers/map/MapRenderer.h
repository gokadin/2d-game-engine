#ifndef SFMLDEMO_MAPRENDERER_H
#define SFMLDEMO_MAPRENDERER_H

#include "../../Renderer.h"
#include "../../../data/definitions/map/MapGraphics.h"
#include "../../../data/definitions/map/MapState.h"
#include "../../../data/definitions/map/MapBounds.h"

#define DEBUG_MAP true

class MapRenderer : public Renderer
{
public:
    MapRenderer(MapGraphics *graphics, MapState *state, MapBounds *bounds);

    void update();
    void draw(sf::RenderWindow *window);

private:
    MapGraphics *m_graphics;
    MapState *m_state;
    MapBounds *m_bounds;
    sf::Texture m_gridTexture;
    sf::Sprite m_gridSprite;
    sf::Texture m_shadedGridTexture;
    sf::Sprite m_shadedGridSprite;
};

#endif //SFMLDEMO_MAPRENDERER_H
