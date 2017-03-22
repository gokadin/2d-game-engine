#ifndef SFMLDEMO_UICOMPONENT_H
#define SFMLDEMO_UICOMPONENT_H

#include "../../core/GameComponent.h"
#include "../../UI/main/SkillBar.h"

class UserInterface : public GameComponent
{
public:
    UserInterface();
    ~UserInterface();

    void update();
    void draw(sf::RenderWindow *window);
    bool isMouseOnUI(int x, int y);

private:
    SkillBar *m_skillBar;
};

#endif //SFMLDEMO_UICOMPONENT_H
