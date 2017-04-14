#ifndef SFMLDEMO_SUMMONERUPDATER_H
#define SFMLDEMO_SUMMONERUPDATER_H

#include "../MonsterManagerUpdater.h"
#include "../../../monsters/MonsterManager.h"

class SummonerUpdater : public MonsterManagerUpdater
{
public:
    SummonerUpdater(MapBounds *mapBounds, MapState *mapState, CharacterGraphics *characterGraphics,
                    const std::map<int, Monster *> &monsters, MonsterManager *minionManager);

    void update();

private:
    const int RESURRECT_CHECK_FRAMES_BETWEEN = Engine::UPS / 4;

    int m_resurrectCheckTimer;
    MonsterManager *m_minionManager;

    void resurrectDeadMinions();
};

#endif //SFMLDEMO_SUMMONERUPDATER_H
