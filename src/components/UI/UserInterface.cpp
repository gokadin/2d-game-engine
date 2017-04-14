#include <SFML/Window/Event.hpp>
#include "UserInterface.h"

UserInterface::UserInterface(GameFonts *fonts, EquipmentManager *equipmentManager, QuestTracker *questTracker):
        m_currentMouseOverElement(nullptr)
{
    m_skillBar = new SkillBar(fonts);
    m_inventorySideBar = new InventorySideBar(equipmentManager);
    m_questTrackerUI = new QuestTrackerUI(fonts, questTracker);
}

UserInterface::~UserInterface()
{
    m_currentMouseOverElement = nullptr;

    delete m_skillBar;
    delete m_inventorySideBar;
    delete m_questTrackerUI;
}

void UserInterface::processEvent(sf::Event &event)
{
    m_currentMouseOverElement->processEvent(event);
}

void UserInterface::update()
{
    m_skillBar->update();
    m_inventorySideBar->update();
    m_questTrackerUI->update();
}

void UserInterface::draw(sf::RenderWindow *window)
{
    m_skillBar->draw(window);
    m_inventorySideBar->draw(window);
    m_questTrackerUI->draw(window);
}

bool UserInterface::isMouseOnUI(int x, int y)
{
    if (m_inventorySideBar->isMouseOnUI(x, y))
    {
        m_currentMouseOverElement = m_inventorySideBar;
        return true;
    }

    if (m_questTrackerUI->isMouseOnUI(x, y))
    {
        m_currentMouseOverElement = m_questTrackerUI;
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

void UserInterface::handleEvent(std::shared_ptr<Event> event)
{
    switch (event->type()) {
        case event_type::CHARACTER_EXPERIENCE_GAINED:
            handleCharacterExperienceGained(std::static_pointer_cast<CharacterExperienceGainedEvent>(event));
            break;
    }
}

void UserInterface::handleCharacterExperienceGained(std::shared_ptr<CharacterExperienceGainedEvent> event)
{
    m_skillBar->handleCharacterExperienceGained(event);
}
