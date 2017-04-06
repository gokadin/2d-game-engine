#include <SFML/Window/Event.hpp>
#include "UserInterface.h"

UserInterface::UserInterface(EquipmentManager *equipmentManager):
        m_currentMouseOverElement(nullptr)
{
    m_skillBar = new SkillBar();
    m_inventorySideBar = new InventorySideBar(equipmentManager);
}

UserInterface::~UserInterface()
{
    m_currentMouseOverElement = nullptr;

    delete m_skillBar;
    delete m_inventorySideBar;
}

void UserInterface::processEvent(sf::Event &event)
{
    m_currentMouseOverElement->processEvent(event);
}

void UserInterface::update()
{
    m_skillBar->update();
    m_inventorySideBar->update();
}

void UserInterface::draw(sf::RenderWindow *window)
{
    m_skillBar->draw(window);
    m_inventorySideBar->draw(window);
}

bool UserInterface::isMouseOnUI(int x, int y)
{
    if (m_inventorySideBar->isMouseOnUI(x, y))
    {
        m_currentMouseOverElement = m_inventorySideBar;
        return true;
    }

    return false;
}

void UserInterface::toggleInventory()
{
    m_inventorySideBar->isOpen() ? m_inventorySideBar->close() : m_inventorySideBar->open();
}

void UserInterface::closeOpenWindows()
{
    m_inventorySideBar->close();
}

bool UserInterface::hasOpenWindows()
{
    return m_inventorySideBar->isOpen();
}
