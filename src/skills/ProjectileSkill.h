#ifndef SFMLDEMO_PROJECTILESKILL_H
#define SFMLDEMO_PROJECTILESKILL_H

#include "Skill.h"
#include "Projectile.h"

class ProjectileSkill : public Skill
{
public:
    ProjectileSkill(int castTime, int castAnimationTime);
    virtual ~ProjectileSkill();

    virtual void update();
    virtual void draw(sf::RenderWindow *window);

    inline std::vector<Projectile *>& projectiles() { return m_projectiles; }

protected:
    std::vector<Projectile *> m_projectiles;
    int m_projectileDamage;

    void addProjectile(Projectile *projectile);
};

#endif //SFMLDEMO_PROJECTILESKILL_H
