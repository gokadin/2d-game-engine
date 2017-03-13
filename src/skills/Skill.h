#ifndef SFMLDEMO_SKILL_H
#define SFMLDEMO_SKILL_H

#include <SFML/Graphics/RenderWindow.hpp>

class Skill
{
public:
    virtual bool canActivate() = 0;
    virtual void activate() {};
    virtual void activate(int targetX, int targetY) {};
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow *window) = 0;

    inline bool isActive() { return m_isActive; }

protected:
    bool m_isActive;
};

#endif //SFMLDEMO_SKILL_H
