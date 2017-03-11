#ifndef SFMLDEMO_DATAPROVIDERS_H
#define SFMLDEMO_DATAPROVIDERS_H

#include <vector>
#include <iostream>
#include "../states/GameState.h"
#include "providers/Provider.h"
#include "persistence/SaveReader.h"

class DataProvider
{
public:
    DataProvider(GameState& state, int screenWidth, int screenHeight);
    ~DataProvider();

    void load();

private:
    std::vector<Provider *> providers;
    SaveReader saveReader;
};

#endif //SFMLDEMO_DATAPROVIDERS_H
