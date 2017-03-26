#include <iostream>
#include "Item.h"

Item::Item(std::string iconFilename, bool isEquipable):
        m_isEquipable(isEquipable)
{
    if (!m_icon.loadFromFile(iconFilename))
    {
        std::cout << "Could not load icon texture." << std::endl;
    }

    m_iconSprite.setTexture(m_icon);
}
