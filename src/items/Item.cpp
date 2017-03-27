#include <iostream>
#include "Item.h"

Item::Item(std::string iconFilename, bool isEquipable, int slotSize):
        m_isEquipable(isEquipable), m_slotSize(slotSize)
{
    if (!m_icon.loadFromFile(iconFilename))
    {
        std::cout << "Could not load icon texture." << std::endl;
    }

    m_iconSprite.setTexture(m_icon);
}
