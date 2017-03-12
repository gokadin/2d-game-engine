#include <iostream>
#include "MonsterRenderer.h"

MonsterRenderer::MonsterRenderer(GameState &state):
        Renderer(state)
{
    for (MonsterState monsterState : state.monsters)
    {
        if (textures.find(monsterState.type) == textures.end())
        {
            textures[monsterState.type] = sf::Texture();
            if (!textures[monsterState.type].loadFromFile(monsterState.texture))
            {
                std::cout << "ERROR WITH TEXTURE" << std::endl;
            }
        }

        sprites.push_back(sf::Sprite(textures[monsterState.type]));
    }
}

void MonsterRenderer::draw(sf::RenderWindow *window)
{
    for (int i = 0; i < sprites.size(); i++)
    {
        sprites[i].setTextureRect(sf::IntRect(state.monsters[i].spriteOffsetX, state.monsters[i].spriteOffsetY,
                                          state.monsters[i].spriteWidth, state.monsters[i].spriteHeight));
        sprites[i].setPosition(sf::Vector2f(state.monsters[i].x - state.monsters[i].spriteWidth / 2 - state.map.cx + state.config.width / 2,
                                            state.monsters[i].y - state.monsters[i].spriteHeight / 2 - state.map.cy + state.config.height / 2));

        window->draw(sprites[i]);
    }
}
