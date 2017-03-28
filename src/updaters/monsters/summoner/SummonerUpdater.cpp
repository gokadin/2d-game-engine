#include "SummonerUpdater.h"
#include "../../../monsters/common/summoner/Summoner.h"

SummonerUpdater::SummonerUpdater(MapBounds *mapBounds, CharacterGraphics *characterGraphics,
                                 const std::map<int, Monster *> &monsters, MonsterManager *minions):
        MonsterManagerUpdater(mapBounds, characterGraphics, monsters), m_minionManager(minions)
{}

void SummonerUpdater::update()
{
    MonsterManagerUpdater::update();

    resurectDeadMinions();
}

void SummonerUpdater::resurectDeadMinions()
{
    Summoner *summoner = NULL;
    for (std::pair<int, Monster *> pair : m_monsters)
    {
        if (pair.second->isAlive())
        {
            summoner = (Summoner*)pair.second;
            break;
        }
    }

    if (summoner == NULL)
    {
        return;
    }

    if (m_minionManager->totalAliveMonsters() < m_minionManager->totalMonsters())
    {
        Monster *minion = m_minionManager->findAnyDeadMonster();
        if (minion == NULL)
        {
            return;
        }

        summoner->resurectMinion(minion);
    }
}
