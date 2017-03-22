#ifndef SFMLDEMO_ZOMBIEUPDATER_H
#define SFMLDEMO_ZOMBIEUPDATER_H

#include "../MonsterManagerUpdater.h"

class ZombieUpdater : public MonsterManagerUpdater
{
public:
    ZombieUpdater(MapBounds *mapBounds, CharacterGraphics *characterGraphics, std::map<int, Monster *> monsters);

    void update();

private:
    int m_counter;
    float m_mul;
};

#endif //SFMLDEMO_ZOMBIEUPDATER_H
