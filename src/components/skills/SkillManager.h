#ifndef SFMLDEMO_SKILLMANAGER_H
#define SFMLDEMO_SKILLMANAGER_H

#include <map>
#include "../../core/GameComponent.h"
#include "../../utils/Observable.h"
#include "../../skills/Skill.h"
#include "../../enums/SkillNames.h"

class SkillManager : public GameComponent, public Observable
{
public:
    SkillManager();
    ~SkillManager();

    void update();
    void draw(sf::RenderWindow *window);
    void activate(int slotIndex, int targetX, int targetY);
    void assign(int slotIndex, skill_names name);

private:
    const int NUM_SLOTS = 6;

    std::vector<skill_names> slots;
    std::map<skill_names, Skill *> skills;
};

#endif //SFMLDEMO_SKILLMANAGER_H
