#include "SkillManagerUpdater.h"

SkillManagerUpdater::SkillManagerUpdater(Monsters *monsters, MapBounds *m_bounds, MapGraphics *mapGraphics,
                                         std::vector<skill_names> &slots, std::map<skill_names, Skill *> &skills):
        m_monsters(monsters), m_bounds(m_bounds), m_mapGraphics(mapGraphics),
        m_slots(slots), m_skills(skills)
{}

void SkillManagerUpdater::update()
{
    for (skill_names name : m_slots)
    {
        if (name == skill_names::NONE || !m_skills[name]->isActive())
        {
            continue;
        }

        if (m_skills[name]->isProjectile())
        {
            updateProjectiles((ProjectileSkill*)m_skills[name]);
        }

        m_skills[name]->update();
    }
}

void SkillManagerUpdater::updateProjectiles(ProjectileSkill *skill)
{
    for (Projectile *projectile : skill->projectiles())
    {
        if (projectile->isFlying())
        {
            updateFlyingProjectile(projectile);
        }

        if (projectile->isHitting())
        {
            updateHittingProjectile(projectile);
        }
    }
}

void SkillManagerUpdater::updateFlyingProjectile(Projectile *projectile)
{
    int boundI = m_bounds->indexFromPosition(projectile->x());
    int boundJ = m_bounds->indexFromPosition(projectile->y());
    if (m_bounds->areIndexesOutOfBounds(boundI, boundJ))
    {
        projectile->cancel();
        return;
    }

    detectCollision(projectile, boundI, boundJ);
}

void SkillManagerUpdater::updateHittingProjectile(Projectile *projectile)
{
    // ...
    // monster damage should be here?
}

void SkillManagerUpdater::detectCollision(Projectile *projectile, int boundI, int boundJ)
{
    int boundValue = m_bounds->get(boundI, boundJ);

    if (boundValue > 0)
    {
        projectile->hit();
    }

    if (boundValue > 1000)
    {
        processMonsterCollision(projectile, boundI, boundJ, boundValue);
    }
}

void SkillManagerUpdater::processMonsterCollision(Projectile *projectile, int boundI, int boundJ, int boundValue)
{
    projectile->hitMonster(m_monsters->findMonster(boundValue));
}
