#ifndef SFMLDEMO_THOUSANDTHRUTS_H
#define SFMLDEMO_THOUSANDTHRUTS_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../../Weapon.h"

class ThousandTruths : public Weapon
{
public:
    ThousandTruths();

    void draw(sf::RenderWindow *window);

    void setPhase(int phase) { m_phase = phase; }

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    int m_phase;
};

#endif //SFMLDEMO_THOUSANDTHRUTS_H
