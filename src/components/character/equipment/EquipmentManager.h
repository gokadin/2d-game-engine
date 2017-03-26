#ifndef SFMLDEMO_EQUIPMENTMANAGER_H
#define SFMLDEMO_EQUIPMENTMANAGER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../../../items/weapons/swords/1h/ThousandTruths.h"
#include "../../../data/definitions/character/CharacterStats.h"

class EquipmentManager
{
public:
    EquipmentManager(CharacterStats *characterStats);

    void draw(sf::RenderWindow *window);
    void setStage(int stage) { if (m_mainHand != NULL) { m_mainHand->setPhase(stage); } }
    void equipMainHand(Weapon *weapon);
    void unequipMainHand(Weapon *weapon);

private:
    CharacterStats *m_characterStats;

    Weapon *m_mainHand;

    void addStats(EquipableItem *item);
    void removeStats(EquipableItem *item);
};

#endif //SFMLDEMO_EQUIPMENTMANAGER_H
