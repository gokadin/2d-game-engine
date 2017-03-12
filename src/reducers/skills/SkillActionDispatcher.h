#ifndef SFMLDEMO_SKILLACTIONDISPATCHER_H
#define SFMLDEMO_SKILLACTIONDISPATCHER_H

#include <map>
#include "../Reducer.h"
#include "SkillReducer.h"

class SkillActionDispatcher : public Reducer
{
public:
    SkillActionDispatcher(GameState &state);
    ~SkillActionDispatcher();

    void process(action_types type, int x, int y);

private:
    std::map<skill_names, SkillReducer *> skillReducers;
};

#endif //SFMLDEMO_SKILLACTIONDISPATCHER_H
