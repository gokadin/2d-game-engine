#include "Character.h"
#include "../../events/skillEvents/SkillActivatedEvent.h"
#include "../../animations/character/skillCasts/InstantCastAnimation.h"
#include "../../events/monsters/MonsterDiedEvent.h"

Character::Character()
{
    m_graphics = new CharacterGraphics();
    m_state = new CharacterState();
    m_stats = new CharacterStats();
    m_stats->subscribeParent(this);
    m_equipmentManager = new EquipmentManager(m_stats);
    m_animations = new CharacterAnimations(m_state, m_graphics, m_equipmentManager);
    m_renderer = new CharacterRenderer(m_graphics);

    ((InstantCastAnimation&)(m_animations->get(character_animation_type::INSTANT_CAST))).subscribe(this);
}

Character::~Character()
{
    delete m_animations;
    delete m_graphics;
    delete m_stats;
    delete m_equipmentManager;
    delete m_state;
    delete m_renderer;
}

void Character::update()
{
    m_animations->update();
    m_renderer->update();
}

void Character::draw(sf::RenderWindow *window)
{
    m_renderer->draw(window);

    m_equipmentManager->draw(window);
}

void Character::handleChildEvent(std::shared_ptr<Event> event)
{
    notifyObservers(event);
}

void Character::handleEvent(std::shared_ptr<Event> event)
{
    switch (event->type())
    {
        case event_type::SKILL_ACTIVATED:
            castSpell((std::static_pointer_cast<SkillActivatedEvent>(event)->skill()));
            break;
        case event_type::INSTANT_CAST_ANIMATION_ENDED:
            m_state->setMovementPaused(false);
            m_state->setIsCasting(false);
            break;
        case event_type::MONSTER_DIED:
            handleMonsterDied((std::static_pointer_cast<MonsterDiedEvent>(event))->monster());
            break;
    }
}

void Character::castSpell(Skill *skill)
{
    m_state->setMovementPaused(true);
    m_state->setIsCasting(true);

    if (skill->isInstantCast())
    {
        ((InstantCastAnimation&)(m_animations->get(character_animation_type::INSTANT_CAST))).start(*skill);
    }
}

void Character::inflictDamage(int damage)
{
    m_currentLife -= damage;
    if (m_currentLife <= 0)
    {
        // ...
    }
}

void Character::handleMonsterDied(Monster *monster) {
    m_stats->handleMonsterDied(monster);
}
