#ifndef SFMLDEMO_EQUIPABLEITEM_H
#define SFMLDEMO_EQUIPABLEITEM_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Item.h"
#include "../enums/items/EquipmentType.h"

class EquipableItem : public Item
{
public:
    EquipableItem(std::string iconFilename, std::string equippedIconFilename, equipment_type type);

    virtual void draw(sf::RenderWindow *window) = 0;

    inline equipment_type type() { return m_type; }
    inline sf::Sprite& equippedIcon() { return m_equippedSprite; }
    inline int spellPower() { return m_spellPower; }

protected:
    equipment_type m_type;
    sf::Texture m_equippedIcon;
    sf::Sprite m_equippedSprite;
    int m_spellPower;
};

#endif //SFMLDEMO_EQUIPABLEITEM_H
