#ifndef SFMLDEMO_UIOBJECT_H
#define SFMLDEMO_UIOBJECT_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class UIObject
{
public:
    UIObject(int width, int height);

    virtual void draw(sf::RenderWindow *window);
    bool isMouseOnButton(int x, int y);

    void setOutlineThickness(float thickness);
    void setOutlineColor(sf::Color color);
    void setFillColor(sf::Color color);
    void setPosition(int x, int y);
    void setPosition(float x, float y);

protected:
    sf::RectangleShape m_mainBox;
};

#endif //SFMLDEMO_UIOBJECT_H
