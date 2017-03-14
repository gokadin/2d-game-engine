#ifndef SFMLDEMO_ENGINE_H
#define SFMLDEMO_ENGINE_H

#include <SFML/Graphics.hpp>

const int UPDATE_INTERVAL_MU = 7000;
const int SECOND_IN_MU = 1000000;

class Engine
{
public:
    static const int UPS = 120;
    static const int SCREEN_WIDTH = 1920;
    static const int SCREEN_HEIGHT = 1080;
    static const int HALF_SCREEN_WIDTH = SCREEN_WIDTH / 2;
    static const int HALF_SCREEN_HEIGHT = SCREEN_HEIGHT / 2;
    static const int CX = SCREEN_WIDTH / 2;
    static const int CY = SCREEN_HEIGHT / 2;

    Engine();
    ~Engine();

    void run();
};

#endif //SFMLDEMO_ENGINE_H
