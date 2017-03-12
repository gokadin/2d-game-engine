#ifndef SFMLDEMO_UPDATEDISPATCHER_H
#define SFMLDEMO_UPDATEDISPATCHER_H

#include <vector>
#include <iostream>
#include "../updaters/Updater.h"
#include "../updaters/map/MapUpdater.h"
#include "../updaters/skills/SkillUpdater.h"
#include "../updaters/character/CharacterUpdater.h"

class UpdateDispatcher
{
public:
    UpdateDispatcher(GameState& state):
            state(state)
    {
        updaters.push_back(new MapUpdater(state));
        updaters.push_back(new CharacterUpdater(state));
        updaters.push_back(new SkillUpdater(state));
    }

    ~UpdateDispatcher()
    {
        for (Updater *updater : updaters)
        {
            updater = NULL;
            delete updater;
        }
        updaters.clear();
    }

    void update()
    {
        for (int i = 0; i < updaters.size(); i++)
        {
            updaters[i]->update();
        }
    }

private:
    GameState& state;
    std::vector<Updater *> updaters;
};

#endif //SFMLDEMO_UPDATEDISPATCHER_H
