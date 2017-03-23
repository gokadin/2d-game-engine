#include <iostream>
#include "ThousandTruths.h"
#include "../../../../core/Engine.h"

ThousandTruths::ThousandTruths():
        m_phase(0)
{
    if (!m_texture.loadFromFile("../src/storage/game/items/weapons/swords/1h/thousandTruths/texture.png"))
    {
        std::cout << "Could not load texture." << std::endl;
    }

    m_sprite.setTexture(m_texture);
}

void ThousandTruths::draw(sf::RenderWindow *window)
{
    m_sprite.setTextureRect(sf::IntRect(m_phase * 64, 0, 64, 64));
    m_sprite.setPosition(Engine::CX - 75, Engine::CY - 75);

    window->draw(m_sprite);
}
