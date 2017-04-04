#ifndef SFMLDEMO_STANDINGTORCH_H
#define SFMLDEMO_STANDINGTORCH_H

#include "../AnimatedMapObject.h"
#include "../../../../rendering/SortedRenderer.h"

class StandingTorch : public AnimatedMapObject
{
public:
    StandingTorch(SortedRenderer *sortedRenderer, MapState *mapState);
};

#endif //SFMLDEMO_STANDINGTORCH_H
