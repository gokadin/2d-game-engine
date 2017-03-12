#include "SkillUpdateDispatcher.h"
#include "fireball/FireballUpdater.h"

SkillUpdateDispatcher::SkillUpdateDispatcher(GameState &state):
        Updater(state)
{
    skillUpdaters[skill_names::FIREBALL] = new FireballUpdater(state);
}

SkillUpdateDispatcher::~SkillUpdateDispatcher()
{
    for (std::pair<skill_names, SkillUpdater *> pair : skillUpdaters)
    {
        pair.second = NULL;
        delete pair.second;
    }
    skillUpdaters.clear();
}

void SkillUpdateDispatcher::update()
{
    for (SkillState skillState : state.character.skills)
    {
        if (skillState.name == skill_names::NONE)
        {
            continue;
        }

        skillUpdaters[skillState.name]->update();
    }
}
