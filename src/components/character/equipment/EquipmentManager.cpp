#include "EquipmentManager.h"

EquipmentManager::EquipmentManager()
{
    m_mainHand = new ThousandTruths();
}

EquipmentManager::~EquipmentManager()
{
    delete m_mainHand;
}

void EquipmentManager::draw(sf::RenderWindow *window)
{
    m_mainHand->draw(window);
}
