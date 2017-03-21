#ifndef SFMLDEMO_SKILLBAR_H
#define SFMLDEMO_SKILLBAR_H

#include "../UIElement.h"

class SkillBar : public UIElement
{
public:
    void update();
    void draw(sf::RenderWindow *window);
};

#endif //SFMLDEMO_SKILLBAR_H
