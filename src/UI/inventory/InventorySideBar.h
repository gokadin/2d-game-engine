#ifndef SFMLDEMO_INVENTORYSIDEBAR_H
#define SFMLDEMO_INVENTORYSIDEBAR_H

#include <SFML/Graphics/RectangleShape.hpp>
#include "../UIElement.h"
#include "../../items/Item.h"
#include "../../items/weapons/swords/1h/ThousandTruths.h"
#include "../../components/character/equipment/EquipmentManager.h"
#include <map>

struct EquipmentSlot
{
    int x;
    int y;
    int width;
    int height;
    Item *item;
};

struct InventorySlot
{
    int x;
    int y;
    Item *item;
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
    std::map<equipment_type, EquipmentSlot> m_equipmentSlots;
    Item *m_grabbedItem;

    ThousandTruths *tempS;

    void processMouseButtonPressed(sf::Event &event);
    void processMouseButtonReleased(sf::Event &event);
    void drawSlotItems(sf::RenderWindow *window);
    InventorySlot* mouseOverInventorySlot(int mouseX, int mouseY);
    EquipmentSlot* mouseOverEquipmentSlot(int mouseX, int mouseY);
};

#endif //SFMLDEMO_INVENTORYSIDEBAR_H
