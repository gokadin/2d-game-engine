#ifndef SFMLDEMO_EFFECTMANAGER_H
#define SFMLDEMO_EFFECTMANAGER_H

#include <map>
#include "Effect.h"

class EffectManager
{
public:
    ~EffectManager();

    void update();
    void refresh(std::string id, Effect *effect);

private:
    std::map<std::string, Effect *> m_effects;
};

#endif //SFMLDEMO_EFFECTMANAGER_H
