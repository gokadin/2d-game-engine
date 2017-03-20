#ifndef SFMLDEMO_SKILLMANAGERUPDATER_H
#define SFMLDEMO_SKILLMANAGERUPDATER_H

#include "../Updater.h"
#include "../../data/definitions/map/MapData.h"
#include "../../components/monsters/Monsters.h"
#include "../../enums/SkillNames.h"
#include "../../skills/Skill.h"
#include "../../data/definitions/map/MapGraphics.h"

class SkillManagerUpdater : Updater
{
public:
    SkillManagerUpdater(Monsters *monsters, MapData *mapData, MapGraphics *mapGraphics, std::vector<skill_names> &slots,
                        std::map<skill_names, Skill *> &skills);

    void update();

private:
    Monsters *m_monsters;
    MapData *m_mapData;
    MapGraphics *m_mapGraphics;
    std::vector<skill_names> &m_slots;
    std::map<skill_names, Skill *> &m_skills;
    std::vector<std::vector<int>> &m_bounds;
};

#endif //SFMLDEMO_SKILLMANAGERUPDATER_H
