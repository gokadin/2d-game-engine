#include <iostream>
#include "EquipableItem.h"

EquipableItem::EquipableItem(std::string iconFilename, std::string equippedIconFilename, equipment_type type):
        Item(iconFilename, true), m_spellPower(0), m_type(type)
{
    if (!m_equippedIcon.loadFromFile(equippedIconFilename))
    {
        std::cout << "Could not load equipped icon texture." << std::endl;
    }

    m_equippedSprite.setTexture(m_equippedIcon);
}
