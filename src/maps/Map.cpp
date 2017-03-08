#include "Map.h"

Map::Map(Actions *actions)
{
    actions->subscribe(this);
}

Map::~Map() {}
