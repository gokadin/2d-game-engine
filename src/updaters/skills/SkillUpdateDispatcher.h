#ifndef SFMLDEMO_SKILLUPDATEMANAGER_H
#define SFMLDEMO_SKILLUPDATEMANAGER_H

#include <map>
#include "../Updater.h"
#include "SkillUpdater.h"

class SkillUpdateDispatcher : public Updater
{
public:
    SkillUpdateDispatcher(GameState &state);
    ~SkillUpdateDispatcher();

    void update();

private:
    std::map<skill_names, SkillUpdater *> skillUpdaters;
};

#endif //SFMLDEMO_SKILLUPDATEMANAGER_H
