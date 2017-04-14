#ifndef SFMLDEMO_CHARACTER_H
#define SFMLDEMO_CHARACTER_H

#include "../../core/GameComponent.h"
#include "../../utils/observable/Observer.h"
#include "../../data/definitions/character/CharacterStats.h"
#include "../../data/definitions/character/CharacterState.h"
#include "../../data/definitions/character/CharacterGraphics.h"
#include "../../animations/character/CharacterAnimations.h"
#include "../../skills/Skill.h"
#include "../../rendering/renderers/character/CharacterRenderer.h"
#include "equipment/EquipmentManager.h"
#include "../../common/MortalEntity.h"
#include "../../utils/observable/ChildObserver.h"

class Character : public GameComponent, public MortalEntity, public Observer, public Observable, public ChildObserver
{
public:
    Character();
    ~Character();

    void update();
    void draw(sf::RenderWindow *window);
    void handleEvent(std::shared_ptr<Event> event);
    void handleChildEvent(std::shared_ptr<Event> event);

    inline CharacterStats *stats() { return m_stats; }
    inline CharacterState *state() { return m_state; }
    inline CharacterGraphics *graphics() { return m_graphics; }
    inline EquipmentManager *equipmentManager() { return m_equipmentManager; }

    void inflictDamage(int damage);

private:
    CharacterStats *m_stats;
    CharacterState *m_state;
    EquipmentManager *m_equipmentManager;
    CharacterGraphics *m_graphics;
    CharacterAnimations *m_animations;
    CharacterRenderer *m_renderer;
    // updater

    void castSpell(Skill *skill);
    void handleMonsterDied(Monster *monster);
};

#endif //SFMLDEMO_CHARACTER_H
