#ifndef SFMLDEMO_SKILLBAR_H
#define SFMLDEMO_SKILLBAR_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../UIElement.h"

class SkillBar : public UIElement
{
public:
    SkillBar();

    void update();
    void draw(sf::RenderWindow *window);

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    int m_width;
    int m_height;
    int m_x;
    int m_y;
};

#endif //SFMLDEMO_SKILLBAR_H
