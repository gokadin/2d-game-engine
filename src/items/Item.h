#ifndef SFMLDEMO_ITEM_H
#define SFMLDEMO_ITEM_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Item
{
public:
    Item(std::string iconFilename, bool isEquipable, int slotSize);

    inline sf::Sprite& icon() { return m_iconSprite; }
    inline bool isEquipable() { return m_isEquipable; }
    inline int slotSize() { return m_slotSize; }

private:
    sf::Texture m_icon;
    sf::Sprite m_iconSprite;
    bool m_isEquipable;
    int m_slotSize;
};

#endif //SFMLDEMO_ITEM_H
