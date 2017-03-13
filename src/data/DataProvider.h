#ifndef SFMLDEMO_DATAPROVIDERS_H
#define SFMLDEMO_DATAPROVIDERS_H

#include <vector>
#include <iostream>
#include "../states/GameState.h"
#include "providers/Provider.h"
#include "persistence/SaveReader.h"
#include "../components/character/Character.h"
#include "../components/skills/SkillManager.h"

class DataProvider
{
public:
    DataProvider(GameState& state, int screenWidth, int screenHeight);
    ~DataProvider();

    void load();

    void loadCharacter(Character *character);
    void loadSkills(SkillManager *skillManager);

private:
    std::vector<Provider *> providers;
    SaveReader saveReader;
};

#endif //SFMLDEMO_DATAPROVIDERS_H
