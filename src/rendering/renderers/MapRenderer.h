#ifndef SFMLDEMO_MAPRENDERER_H
#define SFMLDEMO_MAPRENDERER_H

#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../Renderer.h"

class MapRenderer : public Renderer
{
public:
    MapRenderer(GameState& state);

    void draw(sf::RenderWindow *window);

private:
    sf::Sprite sprite;
    sf::Texture texture;

    void updateView();
};

#endif //SFMLDEMO_MAPRENDERER_H
