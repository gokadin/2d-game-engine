#ifndef SFMLDEMO_SKILLBAR_H
#define SFMLDEMO_SKILLBAR_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../UIElement.h"

class SkillBar : public UIElement
{
public:
    SkillBar();

    void processEvent(sf::Event &event);
    void update();
    void draw(sf::RenderWindow *window);
    bool isMouseOnUI(int x, int y);

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
};

#endif //SFMLDEMO_SKILLBAR_H
