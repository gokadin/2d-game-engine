#include "EquipmentManager.h"

EquipmentManager::EquipmentManager(CharacterStats *characterStats):
        m_characterStats(characterStats), m_mainHand(NULL)
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

void EquipmentManager::unequipMainHand()
{
    if (m_mainHand != NULL)
    {
        removeStats(m_mainHand);
    }

    m_mainHand = NULL;
}

void EquipmentManager::addStats(EquipableItem *item)
{
    m_characterStats->addSpellPower(item->spellPower());
}

void EquipmentManager::removeStats(EquipableItem *item)
{
    m_characterStats->removeSpellPower(item->spellPower());
}
