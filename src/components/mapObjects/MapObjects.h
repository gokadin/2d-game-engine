#ifndef SFMLDEMO_MAPOBJECTS_H
#define SFMLDEMO_MAPOBJECTS_H

#include <vector>
#include "../../core/GameComponent.h"
#include "objects/MapObject.h"
#include "../../data/definitions/map/MapState.h"
#include "../../rendering/SortedRenderer.h"

class MapObjects : public GameComponent
{
public:
    MapObjects(SortedRenderer *sortedRenderer, MapState *mapState);
    ~MapObjects();

    void update();
    void draw(sf::RenderWindow *window);

private:
    std::vector<MapObject *> m_objects;
    MapState *m_mapState;
};

#endif //SFMLDEMO_MAPOBJECTS_H
