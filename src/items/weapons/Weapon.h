#ifndef SFMLDEMO_WEAPON_H
#define SFMLDEMO_WEAPON_H

#include "../EquipableItem.h"

class Weapon : public EquipableItem
{
public:
    Weapon(std::string iconFilename):
            EquipableItem(iconFilename, "../src/storage/game/items/weapons/swords/1h/thousandTruths/equipIcon.png",
                          equipment_type::MAIN_HAND), m_phase(0)
    {}

    void setPhase(int phase) { m_phase = phase; }

protected:
    int m_phase;
};

#endif //SFMLDEMO_WEAPON_H
