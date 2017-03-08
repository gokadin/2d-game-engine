#ifndef SFMLDEMO_MAP_H
#define SFMLDEMO_MAP_H

#include "../windows/Context.h"
#include "../utils/Observer.h"
#include "../core/Actions.h"

class Map : public Context, public Observer
{
public:
    Map(Actions *actions);
    virtual ~Map();
};

#endif //SFMLDEMO_MAP_H
