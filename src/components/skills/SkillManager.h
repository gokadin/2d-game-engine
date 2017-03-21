#ifndef SFMLDEMO_SKILLMANAGER_H
#define SFMLDEMO_SKILLMANAGER_H

#include <map>
#include "../../core/GameComponent.h"
#include "../../utils/Observable.h"
#include "../../skills/Skill.h"
#include "../../enums/SkillNames.h"
#include "../../data/definitions/map/MapState.h"
#include "../../data/definitions/map/MapBounds.h"
#include "../../data/definitions/character/CharacterGraphics.h"
#include "../../data/definitions/map/MapGraphics.h"
#include "../monsters/Monsters.h"
#include "../../updaters/skills/SkillManagerUpdater.h"

class SkillManager : public GameComponent, public Observable
{
public:
    SkillManager(MapState *mapState, MapBounds *mapBounds, MapGraphics *mapGraphics, CharacterGraphics *characterGraphics,
                 Monsters *monsters);
    ~SkillManager();

    void update();
    void draw(sf::RenderWindow *window);
    void activate(int slotIndex, int targetX, int targetY);
    void assign(int slotIndex, skill_names name);

private:
    const int NUM_SLOTS = 6;

    std::vector<skill_names> m_slots;
    std::map<skill_names, Skill *> m_skills;
    MapState *m_mapState;
    MapBounds *m_mapBounds;
    MapGraphics *m_mapGraphics;
    CharacterGraphics *m_characterGraphics;
    Monsters *m_monsters;
    SkillManagerUpdater *m_updater;
};

#endif //SFMLDEMO_SKILLMANAGER_H
