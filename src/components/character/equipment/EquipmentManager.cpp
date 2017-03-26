#include "EquipmentManager.h"

EquipmentManager::EquipmentManager(CharacterStats *characterStats):
        m_characterStats(characterStats)
{}

void EquipmentManager::draw(sf::RenderWindow *window)
{
    if (m_mainHand != NULL)
    {
        m_mainHand->draw(window);
    }
}

void EquipmentManager::equipMainHand(Weapon *weapon)
{
    m_mainHand = weapon;

    addStats(weapon);
}

void EquipmentManager::unequipMainHand(Weapon *weapon)
{
    m_mainHand = NULL;

    removeStats(weapon);
}

void EquipmentManager::addStats(EquipableItem *item)
{
    m_characterStats->addSpellPower(item->spellPower());
}

void EquipmentManager::removeStats(EquipableItem *item)
{
    m_characterStats->removeSpellPower(item->spellPower());
}
