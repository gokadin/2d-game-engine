#include "SkillManager.h"
#include "../../skills/fireball/Fireball.h"
#include "../../events/SkillActivatedEvent.h"

SkillManager::SkillManager()
{
    for (int i = 0; i < NUM_SLOTS; i++)
    {
        slots.push_back(skill_names::NONE);
    }

    skills[skill_names::FIREBALL] = new Fireball();
}

SkillManager::~SkillManager()
{
    for (std::pair<skill_names, Skill *> pair : skills)
    {
        pair.second = NULL;
        delete pair.second;
    }
    skills.clear();
}

void SkillManager::update()
{
    for (skill_names name : slots)
    {
        if (name != skill_names::NONE && skills[name]->isActive())
        {
            skills[name]->update();
        }
    }
}

void SkillManager::draw(sf::RenderWindow *window)
{
    for (skill_names name : slots)
    {
        if (name != skill_names::NONE && skills[name]->isActive())
        {
            skills[name]->draw(window);
        }
    }
}

void SkillManager::activate(int slotIndex, int targetX, int targetY)
{
    if (slotIndex < NUM_SLOTS && skills[slots[slotIndex]]->canActivate())
    {
        skills[slots[slotIndex]]->activate();
        notifyObservers(new SkillActivatedEvent(event_type::SKILL_ACTIVATED, skills[slots[slotIndex]]));
    }
}

void SkillManager::assign(int slotIndex, skill_names name)
{
    if (slotIndex < NUM_SLOTS)
    {
        slots[slotIndex] = name;
    }
}
