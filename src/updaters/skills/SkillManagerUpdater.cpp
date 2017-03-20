#include "SkillManagerUpdater.h"
#include "../../skills/Projectile.h"
#include "../../skills/ProjectileSkill.h"

SkillManagerUpdater::SkillManagerUpdater(Monsters *monsters, MapData *mapData, MapGraphics *mapGraphics,
                                         std::vector<skill_names> &slots, std::map<skill_names, Skill *> &skills):
        m_monsters(monsters), m_mapData(mapData), m_bounds(mapData->bounds()), m_mapGraphics(mapGraphics),
        m_slots(slots), m_skills(skills)
{}

void SkillManagerUpdater::update()
{
    for (skill_names name : m_slots)
    {
        if (name != skill_names::NONE && m_skills[name]->isActive())
        {
            if (m_skills[name]->isProjectile())
            {
                for (Projectile *projectile : ((ProjectileSkill*)m_skills[name])->projectiles())
                {
                    if (projectile->isFlying())
                    {
                        int boundI = (int)(projectile->x() / m_mapGraphics->tileRadius());
                        int boundJ = (int)(projectile->y() / m_mapGraphics->tileRadius());
                        if (boundI > m_bounds.size() - 1 || boundJ > m_bounds[boundI].size() - 1)
                        {
                            projectile->cancel();
                        }
                        else if (m_bounds[boundI][boundJ] > 0)
                        {
                            if (m_bounds[boundI][boundJ] > 1000)
                            {
                                Monster *monster = m_monsters->findMonster(m_bounds[boundI][boundJ]);
                                monster->inflictDamage(60);
                            }

                            projectile->hit();
                        }
                    }

                    if (projectile->isHitting())
                    {
                        // ...
                    }
                }
            }

            m_skills[name]->update();
        }
    }
}


