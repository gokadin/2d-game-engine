#ifndef SFMLDEMO_INVENTORYSIDEBAR_H
#define SFMLDEMO_INVENTORYSIDEBAR_H

#include "../UIElement.h"

class InventorySideBar : public UIElement
{
public:
    InventorySideBar();

    void update();
    void draw(sf::RenderWindow *window);
    bool isMouseOnUI(int x, int y);
};

#endif //SFMLDEMO_INVENTORYSIDEBAR_H
