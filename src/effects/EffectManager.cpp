#include "EffectManager.h"

EffectManager::~EffectManager()
{
    for (auto pair : m_effects)
    {
        if (pair.second != nullptr)
        {
            delete pair.second;
        }
    }
}

void EffectManager::update()
{
    for (auto it = m_effects.cbegin(); it != m_effects.cend();)
    {
        if ((*it).second->isCompleted())
        {
            delete (*it).second;
            it = m_effects.erase(it);
            continue;
        }

        (*it).second->update();
        ++it;
    }
}

void EffectManager::refresh(std::string id, Effect *effect)
{
    if (m_effects.count(id))
    {
        delete m_effects[id];
    }

    m_effects[id] = effect;
}
