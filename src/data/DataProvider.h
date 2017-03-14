#ifndef SFMLDEMO_DATAPROVIDERS_H
#define SFMLDEMO_DATAPROVIDERS_H

#include "../components/character/Character.h"
#include "../components/skills/SkillManager.h"
#include "../components/map/Map.h"

class DataProvider
{
public:
    void loadMap(Map *map);
    void loadCharacter(Character *character);
    void loadSkills(SkillManager *skillManager);
};

#endif //SFMLDEMO_DATAPROVIDERS_H
