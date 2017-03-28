#ifndef SFMLDEMO_MINIONMANAGER_H
#define SFMLDEMO_MINIONMANAGER_H

#include "../../MonsterManager.h"
#include "../../../updaters/monsters/minion/MinionUpdater.h"

class MinionManager : public MonsterManager
{
public:
    MinionManager(int baseId, MapState *mapState, MapBounds *bounds, CharacterGraphics *characterGraphics);
    ~MinionManager();

    void update();

private:
    MinionUpdater *m_updater;
};

#endif //SFMLDEMO_MINIONMANAGER_H
