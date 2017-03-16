#ifndef SFMLDEMO_CHARACTERRENDERER_H
#define SFMLDEMO_CHARACTERRENDERER_H

#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "../../Renderer.h"
#include "../../../data/definitions/character/CharacterGraphics.h"

class CharacterRenderer : public Renderer
{
public:
    CharacterRenderer(CharacterGraphics *graphics);

    void draw(sf::RenderWindow *window);

private:
    CharacterGraphics *m_graphics;

    // temp and debug
    sf::RectangleShape m_box;
    sf::RectangleShape m_point;

    void updateSprite();
};

#endif //SFMLDEMO_CHARACTERRENDERER_H
