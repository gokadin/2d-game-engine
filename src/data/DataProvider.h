#ifndef SFMLDEMO_DATAPROVIDERS_H
#define SFMLDEMO_DATAPROVIDERS_H

#include "persistence/SaveReader.h"
#include "../components/character/Character.h"
#include "../components/skills/SkillManager.h"
#include "../components/map/Map.h"

class DataProvider
{
public:
    void loadMap(Map *map);
    void loadCharacter(Character *character);
    void loadSkills(SkillManager *skillManager);

private:
    SaveReader saveReader;
};

#endif //SFMLDEMO_DATAPROVIDERS_H
