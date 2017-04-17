#include "SummonerUpdater.h"
#include "../../../monsters/common/summoner/Summoner.h"

SummonerUpdater::SummonerUpdater(MapBounds *mapBounds, MapState *mapState, CharacterGraphics *characterGraphics,
                                 const std::map<int, Monster *> &monsters, MonsterManager *minions)
        : MonsterManagerUpdater(mapBounds, mapState, characterGraphics, monsters), m_minionManager(minions),
          m_resurrectCheckTimer(0)
{}

void SummonerUpdater::update()
{
    m_resurrectCheckTimer++;
    if (m_resurrectCheckTimer == RESURRECT_CHECK_FRAMES_BETWEEN)
    {
        m_resurrectCheckTimer = 0;
        resurrectDeadMinions();
    }
}

void SummonerUpdater::resurrectDeadMinions()
{
    if (m_minionManager->totalAliveMonsters() == m_minionManager->totalMonsters())
    {
        return;
    }

    Monster *minion = m_minionManager->findAnyDeadMonster();
    if (minion == nullptr)
    {
        return;
    }

    Summoner *availableSummoner = nullptr;
    for (std::pair<int, Monster *> pair : m_monsters)
    {
        auto *summoner = (Summoner*)pair.second;
        if (summoner->isAlive() && summoner->isReadyToResurrect() && summoner->isInResurrectRange(minion))
        {
            availableSummoner = summoner;
            break;
        }
    }

    if (availableSummoner == nullptr)
    {
        return;
    }

    availableSummoner->resurrectMinion(minion);
}
