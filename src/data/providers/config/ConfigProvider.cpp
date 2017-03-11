#include "ConfigProvider.h"

ConfigProvider::ConfigProvider(GameState &state, SaveReader &saveReader, int screenWidth, int screenHeight):
        Provider(state, saveReader),
        screenWidth(screenWidth),
        screenHeight(screenHeight)
{}

void ConfigProvider::load()
{
    state.config.width = screenWidth;
    state.config.height = screenHeight;
    state.config.cx = state.config.width / 2;
    state.config.cy = state.config.height / 2;
}
