#ifndef SFMLDEMO_SKILLMANAGERUPDATER_H
#define SFMLDEMO_SKILLMANAGERUPDATER_H

#include "../Updater.h"
#include "../../data/definitions/map/MapBounds.h"
#include "../../components/monsters/Monsters.h"
#include "../../enums/SkillNames.h"
#include "../../skills/Skill.h"
#include "../../data/definitions/map/MapGraphics.h"
#include "../../skills/ProjectileSkill.h"

class SkillManagerUpdater : Updater
{
public:
    SkillManagerUpdater(Monsters *monsters, MapBounds *mapData, MapGraphics *mapGraphics, std::vector<skill_names> &slots,
                        std::map<skill_names, Skill *> &skills);

    void update();

private:
    Monsters *m_monsters;
    MapBounds *m_bounds;
    MapGraphics *m_mapGraphics;
    std::vector<skill_names> &m_slots;
    std::map<skill_names, Skill *> &m_skills;

    void updateProjectiles(ProjectileSkill *skill);
    void updateFlyingProjectile(Projectile *projectile);
    void updateHittingProjectile(Projectile *projectile);
    void detectCollision(Projectile *projectile, int boundI, int boundJ);
    void processMonsterCollision(Projectile *projectile, int boundValue);
};

#endif //SFMLDEMO_SKILLMANAGERUPDATER_H
