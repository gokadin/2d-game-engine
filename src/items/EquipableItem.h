#ifndef SFMLDEMO_EQUIPABLEITEM_H
#define SFMLDEMO_EQUIPABLEITEM_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Item.h"

class EquipableItem : public Item
{
public:
    EquipableItem();

    virtual void draw(sf::RenderWindow *window) = 0;

    inline int spellPower() { return m_spellPower; }

protected:
    int m_spellPower;
};

#endif //SFMLDEMO_EQUIPABLEITEM_H
