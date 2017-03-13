#include "Character.h"
#include "../../enums/animationTypes/CharacterAnimationType.h"
#include "../../events/SkillActivatedEvent.h"
#include "../../states/CharacterState.h"

Character::Character()
{
    m_animations = new CharacterAnimations();
}

Character::~Character()
{
    delete m_animations;
}

void Character::update()
{
    m_animations->update();
}

void Character::draw(sf::RenderWindow *window)
{

}

void Character::notify(Event *event)
{
    switch (event->type())
    {
        case event_type::SKILL_ACTIVATED:
            castSpell(((SkillActivatedEvent*)event)->skill());
            delete event;
            break;
    }
}

void Character::castSpell(Skill *skill)
{
    m_state.setMovementPaused(true);

    if (skill->isInstantCast())
    {
        m_animations->trigger(character_animation_type::CHARACTER_INSTANT_CAST);
    }
}
