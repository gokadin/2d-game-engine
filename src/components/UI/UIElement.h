#ifndef SFMLDEMO_UIELEMENT_H
#define SFMLDEMO_UIELEMENT_H

#include <SFML/Graphics/RenderWindow.hpp>

class UIElement
{
public:
    UIElement();
    UIElement(int x, int y, int width, int height);

    virtual void processEvent(sf::Event &event) = 0;
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow *window) = 0;
    virtual bool isMouseOnUI(int x, int y);

    void open();
    void close();
    bool isOpen();

protected:
    int m_width;
    int m_height;
    int m_x;
    int m_y;
    bool m_isOpen;
};

#endif //SFMLDEMO_UIELEMENT_H
