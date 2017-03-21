#include "UserInterface.h"

UserInterface::UserInterface()
{
    m_skillBar = new SkillBar();
}

UserInterface::~UserInterface()
{
    delete m_skillBar;
}

void UserInterface::update()
{
    m_skillBar->update();
}

void UserInterface::draw(sf::RenderWindow *window)
{
    m_skillBar->draw(window);
}

bool UserInterface::isMouseOnUI(int x, int y)
{
    return false;
}
