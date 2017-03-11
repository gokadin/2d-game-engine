#ifndef SFMLDEMO_CONFIGPROVIDER_H
#define SFMLDEMO_CONFIGPROVIDER_H

#include "../Provider.h"

class ConfigProvider : public Provider
{
public:
    ConfigProvider(GameState &state, SaveReader &saveReader, int screenWidth, int screenHeight);

    void load();

private:
    int screenWidth;
    int screenHeight;
};

#endif //SFMLDEMO_CONFIGPROVIDER_H
