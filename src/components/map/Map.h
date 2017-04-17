#ifndef SFMLDEMO_MAP_H
#define SFMLDEMO_MAP_H

#include "../../core/GameComponent.h"
#include "../../data/definitions/map/MapGraphics.h"
#include "../../data/definitions/map/MapState.h"
#include "../../rendering/renderers/map/MapRenderer.h"
#include "../../updaters/map/MapUpdater.h"
#include "../../data/definitions/character/CharacterStats.h"
#include "../../data/definitions/map/MapBounds.h"
#include "../../data/definitions/character/CharacterState.h"

const int NODE_SIZE = 32;

class Map : public GameComponent
{
public:
    Map(sf::RenderWindow *window, CharacterStats *characterStats, CharacterGraphics *characterGraphics,
        CharacterState *characterState);
    ~Map();

    void update();
    void draw(sf::RenderWindow *window);

    inline MapGraphics* graphics() { return m_graphics; }
    inline MapState* state() { return m_state; }
    inline MapBounds* bounds() { return m_bounds; }

private:
    MapGraphics *m_graphics;
    MapState *m_state;
    MapBounds *m_bounds;
    MapRenderer *m_renderer;
    MapUpdater *m_updater;
};

#endif //SFMLDEMO_MAP_H
