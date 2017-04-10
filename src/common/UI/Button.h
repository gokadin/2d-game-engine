#ifndef SFMLDEMO_BUTTON_H
#define SFMLDEMO_BUTTON_H

#include <SFML/Graphics/Text.hpp>
#include "UIObject.h"

class Button : public UIObject
{
public:
    Button(int width, int height);
    ~Button();

    void draw(sf::RenderWindow *window);

    void setText(sf::Text *text);

private:
    sf::Text *m_text;
};

#endif //SFMLDEMO_BUTTON_H
