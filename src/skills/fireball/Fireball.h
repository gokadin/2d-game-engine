#ifndef SFMLDEMO_FIREBALL_H
#define SFMLDEMO_FIREBALL_H

#include "../Skill.h"

class Fireball : public Skill
{
public:
    Fireball():
            Skill(0)
    {}

    void update();
    void draw(sf::RenderWindow *window);
    bool canActivate();
    void activate(int targetX, int targetY);
};

#endif //SFMLDEMO_FIREBALL_H
