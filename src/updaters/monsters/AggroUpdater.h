#ifndef SFMLDEMO_AGGROUPDATER_H
#define SFMLDEMO_AGGROUPDATER_H

#include "../../monsters/Monster.h"

class AggroUpdater
{
public:
    AggroUpdater(MapState *mapState);

    void update(Monster *monster);

private:
    MapState *m_mapState;
};

#endif //SFMLDEMO_AGGROUPDATER_H
