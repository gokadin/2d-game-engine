#include "DataProvider.h"
#include "providers/map/MapProvider.h"
#include "providers/character/CharacterProvider.h"
#include "providers/config/ConfigProvider.h"

DataProvider::DataProvider(GameState& state, int screenWidth, int screenHeight):
        saveReader(state)
{
    providers.push_back(new ConfigProvider(state, saveReader, screenWidth, screenHeight));
    providers.push_back(new MapProvider(state, saveReader));
    providers.push_back(new CharacterProvider(state, saveReader));
}

DataProvider::~DataProvider()
{
    for (Provider *provider : providers)
    {
        provider = NULL;
        delete provider;
    }
    providers.clear();
}

void DataProvider::load()
{
    saveReader.read();

    for (int i = 0; i < providers.size(); i++)
    {
        providers[i]->load();
    }
}