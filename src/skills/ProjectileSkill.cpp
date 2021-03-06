#include <iostream>
#include "ProjectileSkill.h"

ProjectileSkill::ProjectileSkill(int castTime, int castAnimationTime):
        Skill(castTime, castAnimationTime, true), m_baseProjectileDamage(0), m_calculatedProjectileDamage(0)
{}

ProjectileSkill::~ProjectileSkill()
{
    for (Projectile *projectile : m_projectiles)
    {
        projectile = NULL;
        delete projectile;
    }
    m_projectiles.clear();
}

void ProjectileSkill::update()
{
    int i = 0;
    while (i < m_projectiles.size())
    {
        if (!m_projectiles[i]->isActive())
        {
            m_projectiles[i] = NULL;
            delete m_projectiles[i];
            m_projectiles.erase(m_projectiles.begin() + i);

            continue;
        }

        m_projectiles[i]->update();
        ++i;
    }
}

void ProjectileSkill::draw(sf::RenderWindow *window)
{
    for (Projectile *projectile : m_projectiles)
    {
        projectile->draw(window);
    }
}

void ProjectileSkill::addProjectile(Projectile *projectile)
{
    m_projectiles.push_back(projectile);
}
