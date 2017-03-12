#ifndef SFMLDEMO_MONSTERRENDERER_H
#define SFMLDEMO_MONSTERRENDERER_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include "../../Renderer.h"
#include "../../../data/providers/monsters/MonsterTypes.h"

class MonsterRenderer : public Renderer
{
public:
    MonsterRenderer(GameState &state);

    void draw(sf::RenderWindow *window);

private:
    std::vector<sf::Sprite> sprites;
    std::map<monster_types, sf::Texture> textures;
};

#endif //SFMLDEMO_MONSTERRENDERER_H
