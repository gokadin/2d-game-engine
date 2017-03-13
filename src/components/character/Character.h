#ifndef SFMLDEMO_CHARACTER_H
#define SFMLDEMO_CHARACTER_H

#include "../../core/GameComponent.h"
#include "../../utils/Observer.h"
#include "../../data/definitions/character/CharacterStats.h"
#include "../../data/definitions/character/CharacterState.h"
#include "../../data/definitions/character/CharacterGraphics.h"
#include "../../animations/character/CharacterAnimations.h"
#include "../../skills/Skill.h"

class Character : public GameComponent, public Observer
{
public:
    Character();
    ~Character();

    void update();
    void draw(sf::RenderWindow *window);
    void notify(Event *event);

    inline CharacterStats& stats() { return m_stats; }
    inline CharacterState& state() { return m_state; }
    inline CharacterGraphics& graphics() { return m_graphics; }

private:
    CharacterStats m_stats;
    CharacterState m_state;
    CharacterGraphics m_graphics;
    CharacterAnimations *m_animations;
    // renderer
    // updater

    void castSpell(Skill *skill);
};

#endif //SFMLDEMO_CHARACTER_H
