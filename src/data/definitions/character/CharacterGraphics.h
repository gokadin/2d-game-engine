#ifndef SFMLDEMO_CHARACTERGRAPHICS_H
#define SFMLDEMO_CHARACTERGRAPHICS_H

#include <SFML/Graphics/Texture.hpp>

class CharacterGraphics
{
public:
    inline sf::Texture& texture() { return m_texture; }
    inline int spriteWidth() { return m_spriteWidth; }
    inline int spriteHeight() { return m_spriteHeight; }
    inline int spriteOffsetX() { return m_spriteOffsetX; }
    inline int spriteOffsetY() { return m_spriteOffsetY; }
    inline int boxWidth() { return m_boxWidth; }
    inline int boxHeight() { return m_boxHeight; }
    inline int legRoom() { return m_legRoom; }

private:
    sf::Texture m_texture;
    int m_spriteWidth;
    int m_spriteHeight;
    int m_spriteOffsetX;
    int m_spriteOffsetY;
    int m_boxWidth;
    int m_boxHeight;
    int m_legRoom;
};

#endif //SFMLDEMO_CHARACTERGRAPHICS_H
