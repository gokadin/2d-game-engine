#include <SFML/Window/Event.hpp>
#include "UserInterface.h"

UserInterface::UserInterface()
{
    m_skillBar = new SkillBar();
    m_inventorySideBar = new InventorySideBar();
}

UserInterface::~UserInterface()
{
    delete m_skillBar;
    delete m_inventorySideBar;
}

void UserInterface::processEvent(sf::Event &event)
{
    switch (event.type)
    {
        case sf::Event::MouseButtonPressed:

            break;
        case sf::Event::MouseButtonReleased:

            break;
    }
}

void UserInterface::update()
{
    m_skillBar->update();
    m_inventorySideBar->update();
}

void UserInterface::draw(sf::RenderWindow *window)
{
    m_inventorySideBar->draw(window);
    m_skillBar->draw(window);
}

bool UserInterface::isMouseOnUI(int x, int y)
{
    if (m_inventorySideBar->isMouseOnUI(x, y))
    {
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
