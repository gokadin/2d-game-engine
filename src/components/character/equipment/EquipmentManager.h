#ifndef SFMLDEMO_EQUIPMENTMANAGER_H
#define SFMLDEMO_EQUIPMENTMANAGER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../../../items/weapons/swords/1h/ThousandTruths.h"

class EquipmentManager
{
public:
    EquipmentManager();
    ~EquipmentManager();

    void draw(sf::RenderWindow *window);
    void setStage(int stage) { m_mainHand->setPhase(stage); }

private:
    ThousandTruths *m_mainHand;
};

#endif //SFMLDEMO_EQUIPMENTMANAGER_H
