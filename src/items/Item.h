#ifndef SFMLDEMO_ITEM_H
#define SFMLDEMO_ITEM_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Item
{
public:
    Item(std::string iconFilename);

    inline sf::Sprite& icon() { return m_iconSprite; }

private:
    sf::Texture m_icon;
    sf::Sprite m_iconSprite;
};

#endif //SFMLDEMO_ITEM_H
