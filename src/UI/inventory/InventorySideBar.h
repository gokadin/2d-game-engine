#ifndef SFMLDEMO_INVENTORYSIDEBAR_H
#define SFMLDEMO_INVENTORYSIDEBAR_H

#include <SFML/Graphics/RectangleShape.hpp>
#include "../UIElement.h"
#include "../../items/Item.h"
#include "../../items/weapons/swords/1h/ThousandTruths.h"

class InventorySideBar : public UIElement
{
public:
    InventorySideBar();
    ~InventorySideBar();

    void processEvent(sf::Event &event);
    void update();
    void draw(sf::RenderWindow *window);
    bool isMouseOnUI(int x, int y);

private:
    const int NUM_SLOTS_IN_ROW = 10;
    const int NUM_SLOTS_IN_COLUMN = 6;

    std::vector<std::vector<Item *>> m_slots;
    std::vector<std::vector<int>> m_slotPositionsX;
    std::vector<std::vector<int>> m_slotPositionsY;
    int m_slotsBeginX;
    int m_slotsBeginY;
    int m_slotsMargin;
    int m_slotSize;
    int m_mainHandSlotX;
    int m_mainHandSlotY;
    int m_mainHandSlotWidth;
    int m_mainHandSlotHeight;
    Item *m_grabbedItem;

    ThousandTruths *tempS;

    void drawSlotItems(sf::RenderWindow *window);
};

#endif //SFMLDEMO_INVENTORYSIDEBAR_H
