#include "SkillManager.h"
#include "../../skills/fireball/Fireball.h"
#include "../../events/SkillActivatedEvent.h"
#include "../../monsters/Monster.h"
#include "../monsters/Monsters.h"

SkillManager::SkillManager(MapState *mapState, MapData *mapData, MapGraphics *mapGraphics,
                           CharacterGraphics *characterGraphics, Monsters *monsters):
        m_mapState(mapState), m_mapData(mapData), m_characterGraphics(characterGraphics), m_mapGraphics(mapGraphics),
        m_bounds(mapData->bounds()), m_monsters(monsters)
{
    for (int i = 0; i < NUM_SLOTS; i++)
    {
        m_slots.push_back(skill_names::NONE);
    }

    m_skills[skill_names::FIREBALL] = new Fireball(mapState);

    m_updater = new SkillManagerUpdater(monsters, mapData, mapGraphics, m_slots, m_skills);
}

SkillManager::~SkillManager()
{
    for (std::pair<skill_names, Skill *> pair : m_skills)
    {
        pair.second = NULL;
        delete pair.second;
    }
    m_skills.clear();

    delete m_updater;
}

void SkillManager::update()
{
    m_updater->update();
}

void SkillManager::draw(sf::RenderWindow *window)
{
    for (skill_names name : m_slots)
    {
        if (name != skill_names::NONE && m_skills[name]->isActive())
        {
            m_skills[name]->draw(window);
        }
    }
}

void SkillManager::activate(int slotIndex, int targetX, int targetY)
{
    if (slotIndex < NUM_SLOTS && m_skills[m_slots[slotIndex]]->canActivate())
    {
        m_skills[m_slots[slotIndex]]->activate(targetX, targetY);
        notifyObservers(new SkillActivatedEvent(event_type::SKILL_ACTIVATED, m_skills[m_slots[slotIndex]]));
    }
}

void SkillManager::assign(int slotIndex, skill_names name)
{
    if (slotIndex < NUM_SLOTS)
    {
        m_slots[slotIndex] = name;
    }
}
