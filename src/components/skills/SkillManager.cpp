#include "SkillManager.h"
#include "../../skills/fireball/Fireball.h"
#include "../../events/skillEvents/SkillActivatedEvent.h"
#include "../../skills/poisonNova/PoisonNova.h"

SkillManager::SkillManager(MapState *mapState, MapBounds *mapBounds, MapGraphics *mapGraphics,
                           CharacterGraphics *characterGraphics, CharacterStats *characterStats, Monsters *monsters):
        m_mapState(mapState), m_characterGraphics(characterGraphics), m_characterStats(characterStats),
        m_mapGraphics(mapGraphics), m_mapBounds(mapBounds), m_monsters(monsters)
{
    for (int i = 0; i < NUM_SLOTS; i++)
    {
        m_slots.push_back(skill_names::NONE);
    }

    m_skills[skill_names::FIREBALL] = new Fireball(mapState);
    m_skills[skill_names::POISON_NOVA] = new PoisonNova(mapState);

    m_updater = new SkillManagerUpdater(monsters, mapBounds, mapGraphics, m_slots, m_skills);
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
        notifyObservers(std::make_shared<SkillActivatedEvent>(m_skills[m_slots[slotIndex]]));
    }
}

void SkillManager::assign(int slotIndex, skill_names name)
{
    if (slotIndex < NUM_SLOTS)
    {
        m_slots[slotIndex] = name;
    }
}

void SkillManager::notify(std::shared_ptr<Event> event)
{
    switch (event->type())
    {
        case event_type::CHARACTER_STATS_CHANGED:
            handleCharacterStatsChanged();
            break;
    }
}

void SkillManager::handleCharacterStatsChanged()
{
    for (std::pair<skill_names, Skill *> pair : m_skills)
    {
        pair.second->handleCharacterStatsChanged(m_characterStats);
    }
}
