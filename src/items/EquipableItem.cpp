#include <iostream>
#include "EquipableItem.h"

EquipableItem::EquipableItem(std::string iconFilename, equipment_type type, int slotSize):
        Item(iconFilename, true, slotSize), m_spellPower(0), m_type(type)
{}
