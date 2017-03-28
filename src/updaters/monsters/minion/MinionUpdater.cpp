#include "MinionUpdater.h"

MinionUpdater::MinionUpdater(MapBounds *mapBounds, CharacterGraphics *characterGraphics,
                             const std::map<int, Monster *> &monsters):
        MonsterManagerUpdater(mapBounds, characterGraphics, monsters)
{}

void MinionUpdater::update()
{
    aggro();
}
