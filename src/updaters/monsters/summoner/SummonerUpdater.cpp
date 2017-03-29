#include "SummonerUpdater.h"
#include "../../../monsters/common/summoner/Summoner.h"

SummonerUpdater::SummonerUpdater(MapBounds *mapBounds, MapState *mapState, CharacterGraphics *characterGraphics,
                                 const std::map<int, Monster *> &monsters, MonsterManager *minions):
        MonsterManagerUpdater(mapBounds, mapState, characterGraphics, monsters), m_minionManager(minions)
{}

void SummonerUpdater::update()
{
    resurectDeadMinions();
}

void SummonerUpdater::resurectDeadMinions()
{
    // need to change all this...
    // should depend on each summoner's availability and position

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
