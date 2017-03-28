#ifndef SFMLDEMO_SUMMONERMANAGER_H
#define SFMLDEMO_SUMMONERMANAGER_H

#include "../../MonsterManager.h"
#include "../../../updaters/monsters/summoner/SummonerUpdater.h"

class SummonerManager : public MonsterManager
{
public:
    SummonerManager(int baseId, MapState *mapState, MapBounds *bounds, CharacterGraphics *characterGraphics,
                    MonsterManager *minionManager);
    ~SummonerManager();

    void update();

private:
    SummonerUpdater *m_updater;
    MonsterManager *m_minionManager;
};

#endif //SFMLDEMO_SUMMONERMANAGER_H
