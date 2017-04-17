#ifndef SFMLDEMO_ISO_H
#define SFMLDEMO_ISO_H

#include <SFML/System.hpp>

class Coords
{
public:
    static sf::Vector2f toIsometric(float x, float y, float offsetX, float offsetY)
    {
        return sf::Vector2f((2 * x - 2 * y) - offsetX, (x + y) - offsetY);
    }

    static void fromIsometric(sf::Vector2f& pos, float offsetX, float offsetY)
    {
        int tx = pos.x + offsetX;
        int ty = pos.y + offsetY;
        float mouseCartX = (2.0f * ty + tx) / 4.0f;
        float mouseCartY = (2.0f * ty - tx) / 4.0f;
        pos.x = mouseCartX;
        pos.y = mouseCartY;
    }

    static void fromIsometric(sf::Vector2i& pos, float offsetX, float offsetY)
    {
        int tx = pos.x + offsetX;
        int ty = pos.y + offsetY;
        float mouseCartX = (2.0f * ty + tx) / 4.0f;
        float mouseCartY = (2.0f * ty - tx) / 4.0f;
        pos.x = mouseCartX;
        pos.y = mouseCartY;
    }
};

#endif //SFMLDEMO_ISO_H
