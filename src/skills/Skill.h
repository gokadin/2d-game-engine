#ifndef SFMLDEMO_SKILL_H
#define SFMLDEMO_SKILL_H

#include <SFML/Graphics/RenderWindow.hpp>

class Skill
{
public:
    Skill(int castTime):
            m_castTime(castTime)
    {}

    virtual bool canActivate() = 0;
    virtual void activate() {};
    virtual void activate(int targetX, int targetY) {};
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow *window) = 0;

    inline bool isActive() { return m_isActive; }
    inline int castTime() { return m_castTime; }
    inline bool isInstantCast() { return m_castTime == 0; };

protected:
    bool m_isActive;
    int m_castTime;
};

#endif //SFMLDEMO_SKILL_H
