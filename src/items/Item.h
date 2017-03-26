#ifndef SFMLDEMO_ITEM_H
#define SFMLDEMO_ITEM_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Item
{
public:
    Item(std::string iconFilename, bool isEquipable);

    inline sf::Sprite& icon() { return m_iconSprite; }
    inline bool isEquipable() { return m_isEquipable; }

private:
    sf::Texture m_icon;
    sf::Sprite m_iconSprite;
    bool m_isEquipable;
};

#endif //SFMLDEMO_ITEM_H
