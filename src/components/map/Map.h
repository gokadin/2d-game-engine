#ifndef SFMLDEMO_MAP_H
#define SFMLDEMO_MAP_H

#include "../../core/GameComponent.h"
#include "../../data/definitions/map/MapGraphics.h"
#include "../../data/definitions/map/MapState.h"

class Map : public GameComponent
{
public:
    Map();
    ~Map();

    void update();
    void draw(sf::RenderWindow *window);

    inline MapGraphics* graphics() { return m_graphics; }
    inline MapState* state() { return m_state; }

private:
    MapGraphics *m_graphics;
    MapState *m_state;
};

#endif //SFMLDEMO_MAP_H
