#ifndef SFMLDEMO_INVENTORYSIDEBAR_H
#define SFMLDEMO_INVENTORYSIDEBAR_H

#include <SFML/Graphics/RectangleShape.hpp>
#include "../UIElement.h"
#include "../../items/Item.h"
#include "../../items/weapons/swords/1h/ThousandTruths.h"
#include "../../components/character/equipment/EquipmentManager.h"
#include <map>

struct InventorySlot
{
    int x;
    int y;
    int width;
    int height;
    int row;
    int column;
    Item *item;
    bool isLastRow;
    bool isFirstRow;
    bool isItemMainSlot;
};

class InventorySideBar : public UIElement
{
public:
    InventorySideBar(EquipmentManager *equipmentManager);
    ~InventorySideBar();

    void processEvent(sf::Event &event);
    void update();
    void draw(sf::RenderWindow *window);
    bool isMouseOnUI(int x, int y);

private:
    EquipmentManager *m_equipmentManager;
    int m_slotsMargin;
    int m_slotSize;
    sf::Vector2i m_inventorySlotsBeginPosition;
    std::vector<std::vector<InventorySlot>> m_slots;
    std::map<equipment_type, InventorySlot> m_equipmentSlots;
    Item *m_grabbedItem;
    sf::RectangleShape m_slotBackground;
    sf::RectangleShape m_slotHighlight;

    ThousandTruths *tempS;

    void processMouseButtonPressed(sf::Event &event);
    void processMouseButtonReleased(sf::Event &event);
    void drawSlotItems(sf::RenderWindow *window);
    void drawSlotBackgrounds(sf::RenderWindow *window);
    void drawSlotHighlights(sf::RenderWindow *window);
    void configureSlotBackground(InventorySlot &slot);
    InventorySlot* mouseOverInventorySlot(int mouseX, int mouseY);
    InventorySlot* mouseOverEquipmentSlot(int mouseX, int mouseY);
};

#endif //SFMLDEMO_INVENTORYSIDEBAR_H
