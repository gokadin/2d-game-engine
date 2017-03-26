#ifndef SFMLDEMO_UICOMPONENT_H
#define SFMLDEMO_UICOMPONENT_H

#include "../../core/GameComponent.h"
#include "../../UI/main/SkillBar.h"
#include "../../UI/inventory/InventorySideBar.h"

class UserInterface : public GameComponent
{
public:
    UserInterface(EquipmentManager *equipmentManager);
    ~UserInterface();

    void processEvent(sf::Event &event);
    void update();
    void draw(sf::RenderWindow *window);
    bool isMouseOnUI(int x, int y);
    void toggleInventory();
    void closeOpenWindows();
    bool hasOpenWindows();

private:
    SkillBar *m_skillBar;
    InventorySideBar *m_inventorySideBar;
    UIElement *m_currentMouseOverElement;
};

#endif //SFMLDEMO_UICOMPONENT_H
