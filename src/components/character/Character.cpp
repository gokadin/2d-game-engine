#include "Character.h"
#include "../../events/SkillActivatedEvent.h"
#include "../../animations/character/skillCasts/InstantCastAnimation.h"

Character::Character()
{
    m_graphics = new CharacterGraphics();
    m_state = new CharacterState();
    m_stats = new CharacterStats();
    m_animations = new CharacterAnimations(m_state, m_graphics);
    m_renderer = new CharacterRenderer(m_graphics);
}

Character::~Character()
{
    delete m_animations;
    delete m_graphics;
    delete m_stats;
    delete m_state;
    delete m_renderer;
}

void Character::update()
{
    m_animations->update();
}

void Character::draw(sf::RenderWindow *window)
{
    m_renderer->draw(window);
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
    m_state->setMovementPaused(true);

    if (skill->isInstantCast())
    {
        ((InstantCastAnimation&)(m_animations->get(character_animation_type::CHARACTER_INSTANT_CAST))).start(*skill);
    }
}
