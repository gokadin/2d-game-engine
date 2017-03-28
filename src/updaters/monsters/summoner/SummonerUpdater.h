#ifndef SFMLDEMO_SUMMONERUPDATER_H
#define SFMLDEMO_SUMMONERUPDATER_H

#include "../MonsterManagerUpdater.h"
#include "../../../monsters/MonsterManager.h"

class SummonerUpdater : public MonsterManagerUpdater
{
public:
    SummonerUpdater(MapBounds *mapBounds, CharacterGraphics *characterGraphics,
                    const std::map<int, Monster *> &monsters, MonsterManager *minionManager);

    void update();

private:
    MonsterManager *m_minionManager;

    void resurectDeadMinions();
};

#endif //SFMLDEMO_SUMMONERUPDATER_H
