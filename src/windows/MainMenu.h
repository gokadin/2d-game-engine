#ifndef SFMLDEMO_MAINMENU_H
#define SFMLDEMO_MAINMENU_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "Context.h"

class MainMenu : public Context
{
public:
    MainMenu();
    ~MainMenu();

    void draw(sf::RenderWindow *window);
};

#endif //SFMLDEMO_MAINMENU_H
