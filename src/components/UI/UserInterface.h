#ifndef SFMLDEMO_UICOMPONENT_H
#define SFMLDEMO_UICOMPONENT_H

#include "../../core/GameComponent.h"
#include "../../UI/main/SkillBar.h"
#include "../../UI/inventory/InventorySideBar.h"

class UserInterface : public GameComponent
{
public:
    UserInterface();
    ~UserInterface();

    void update();
    void draw(sf::RenderWindow *window);
    bool isMouseOnUI(int x, int y);
    void toggleInventory();
    void closeOpenWindows();

private:
    SkillBar *m_skillBar;
    InventorySideBar *m_inventorySideBar;
};

#endif //SFMLDEMO_UICOMPONENT_H
