#include "EquipableItem.h"

EquipableItem::EquipableItem(std::string iconFilename, equipment_type type):
        Item(iconFilename), m_spellPower(0), m_type(type)
{}
