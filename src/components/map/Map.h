#ifndef SFMLDEMO_MAP_H
#define SFMLDEMO_MAP_H

#include "../../core/GameComponent.h"
#include "../../data/definitions/map/MapGraphics.h"
#include "../../data/definitions/map/MapState.h"
#include "../../rendering/renderers/map/MapRenderer.h"
#include "../../updaters/map/MapUpdater.h"
#include "../../data/definitions/character/CharacterStats.h"
#include "../../data/definitions/map/MapData.h"

class Map : public GameComponent
{
public:
    Map(sf::RenderWindow *window, CharacterStats *characterStats);
    ~Map();

    void update();
    void draw(sf::RenderWindow *window);
    void startMoving();
    void stopMovingOnPoint(int x, int y);

    inline MapGraphics* graphics() { return m_graphics; }
    inline MapState* state() { return m_state; }
    inline MapData* data() { return m_data; }

private:
    MapGraphics *m_graphics;
    MapState *m_state;
    MapData *m_data;
    MapRenderer *m_renderer;
    MapUpdater *m_updater;
};

#endif //SFMLDEMO_MAP_H
