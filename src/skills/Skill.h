#ifndef SFMLDEMO_SKILL_H
#define SFMLDEMO_SKILL_H

#include <SFML/Graphics/RenderWindow.hpp>

class Skill
{
public:
    Skill(int castTime, int castAnimationTime, bool isProjectile);

    virtual bool canActivate() = 0;
    virtual void activate(int targetX, int targetY) = 0;
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow *window) = 0;

    inline bool isActive() { return m_isActive; }
    inline int castTime() { return m_castTime; }
    inline bool isInstantCast() { return m_castTime == 0; };
    inline int castAnimationTime() { return m_castAnimationTime; }
    inline bool isProjectile() { return m_isProjectile; }

protected:
    bool m_isActive;
    bool m_isProjectile;
    int m_castTime;
    int m_castAnimationTime;
    bool m_isCastingAnimationFinished;

    void countCastAnimationTime();

private:
    int m_castAnimationTimeCounter;
    int m_castAnimationUpdates;
};

#endif //SFMLDEMO_SKILL_H
