#include "Quests.h"

Quests::Quests(GameFonts *fonts)
        : m_tracker(fonts)
{}

Quests::~Quests()
{

}

void Quests::update()
{
    m_tracker.update();
}

void Quests::draw(sf::RenderWindow *window)
{
    m_tracker.draw(window);
}
