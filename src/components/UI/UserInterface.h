#ifndef SFMLDEMO_UICOMPONENT_H
#define SFMLDEMO_UICOMPONENT_H

#include "../../core/GameComponent.h"
#include "../character/equipment/EquipmentManager.h"
#include "main/SkillBar.h"
#include "inventory/InventorySideBar.h"
#include "questTrackerUI/QuestTrackerUI.h"

class UserInterface : public GameComponent, public Observer
{
public:
    UserInterface(GameFonts *fonts, EquipmentManager *equipmentManager, QuestTracker *questTracker);
    ~UserInterface();

    void processEvent(sf::Event &event);
    void update();
    void draw(sf::RenderWindow *window);
    bool isMouseOnUI(int x, int y);
    void handleEvent(std::shared_ptr<Event> event);
    void toggleInventory();
    void closeOpenWindows();
    bool hasOpenWindows();

private:
    SkillBar *m_skillBar;
    InventorySideBar *m_inventorySideBar;
    QuestTrackerUI *m_questTrackerUI;
    UIElement *m_currentMouseOverElement;

    void handleCharacterExperienceGained(std::shared_ptr<CharacterExperienceGainedEvent> event);
};

#endif //SFMLDEMO_UICOMPONENT_H
