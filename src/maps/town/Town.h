#ifndef SFMLDEMO_TOWN_H
#define SFMLDEMO_TOWN_H

#include "../Map.h"

class Town : public Map
{
public:
    Town(Actions *actions, MapState *mapState);
};

#endif //SFMLDEMO_TOWN_H
