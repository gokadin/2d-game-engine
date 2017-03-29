#include "MinionUpdater.h"

MinionUpdater::MinionUpdater(MapBounds *mapBounds, MapState *mapState, CharacterGraphics *characterGraphics,
                             const std::map<int, Monster *> &monsters):
        MonsterManagerUpdater(mapBounds, mapState, characterGraphics, monsters)
{}

void MinionUpdater::update()
{
    aggro();
}
