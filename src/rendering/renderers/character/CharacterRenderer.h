#ifndef SFMLDEMO_CHARACTERRENDERER_H
#define SFMLDEMO_CHARACTERRENDERER_H

#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../../Renderer.h"
#include "../../../data/definitions/character/CharacterGraphics.h"

class CharacterRenderer : public Renderer
{
public:
    CharacterRenderer(CharacterGraphics *graphics);

    void draw(sf::RenderWindow *window);

private:
    CharacterGraphics *m_graphics;

    void updateSprite();
};

#endif //SFMLDEMO_CHARACTERRENDERER_H
