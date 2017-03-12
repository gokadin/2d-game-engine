#ifndef SFMLDEMO_CHARACTERRENDERER_H
#define SFMLDEMO_CHARACTERRENDERER_H

#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../Renderer.h"

class CharacterRenderer : public Renderer
{
public:
    CharacterRenderer(GameState& state);

    void draw(sf::RenderWindow *window);

private:
    sf::Sprite sprite;
    sf::Texture texture;

    void updateSprite();
};

#endif //SFMLDEMO_CHARACTERRENDERER_H
