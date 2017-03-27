#ifndef SFMLDEMO_EQUIPABLEITEM_H
#define SFMLDEMO_EQUIPABLEITEM_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Item.h"
#include "../enums/items/EquipmentType.h"

class EquipableItem : public Item
{
public:
    EquipableItem(std::string iconFilename, equipment_type type, int slotSize);

    virtual void draw(sf::RenderWindow *window) = 0;

    inline equipment_type type() { return m_type; }
    inline int spellPower() { return m_spellPower; }

protected:
    equipment_type m_type;
    int m_spellPower;
};

#endif //SFMLDEMO_EQUIPABLEITEM_H
