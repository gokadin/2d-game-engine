#ifndef SFMLDEMO_SKILLBAR_H
#define SFMLDEMO_SKILLBAR_H

#include "../UIElement.h"

class SkillBar : public UIElement
{
public:
    SkillBar();

    void processEvent(sf::Event &event);
    void update();
    void draw(sf::RenderWindow *window);
    bool isMouseOnUI(int x, int y);
};

#endif //SFMLDEMO_SKILLBAR_H
