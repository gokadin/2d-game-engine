#ifndef SFMLDEMO_UIELEMENT_H
#define SFMLDEMO_UIELEMENT_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class UIElement
{
public:
    UIElement();

    virtual void processEvent(sf::Event &event) = 0;
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow *window) = 0;
    virtual bool isMouseOnUI(int x, int y) = 0;

    void open();
    void close();
    bool isOpen();

protected:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    int m_width;
    int m_height;
    int m_x;
    int m_y;
    bool m_isOpen;
};

#endif //SFMLDEMO_UIELEMENT_H
