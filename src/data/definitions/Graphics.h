#ifndef SFMLDEMO_GRAPHICS_H
#define SFMLDEMO_GRAPHICS_H

#include <iostream>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Graphics
{
public:
    inline sf::Sprite &sprite() { return m_sprite; }
    inline int spriteWidth() { return m_spriteWidth; }
    inline int spriteHeight() { return m_spriteHeight; }
    inline int spriteOffsetX() { return m_spriteOffsetX; }
    inline int spriteOffsetY() { return m_spriteOffsetY; }

    inline void loadTexture(std::string filename)
    {
        if (!m_texture.loadFromFile(filename))
        {
            std::cout << "ERROR WITH TEXTURE" << std::endl;
        }

        m_sprite.setTexture(m_texture);
    }
    inline void setSpriteOffsetX(int x) { m_spriteOffsetX = x; }
    inline void setSpriteOffsetY(int y) { m_spriteOffsetY = y; }
    inline void setSpriteWidth(int width) { m_spriteWidth = width; }
    inline void setSpriteHeight(int height) { m_spriteHeight = height; }

protected:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    int m_spriteWidth;
    int m_spriteHeight;
    int m_spriteOffsetX;
    int m_spriteOffsetY;
};

#endif //SFMLDEMO_GRAPHICS_H
