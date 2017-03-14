#include "Fireball.h"

Fireball::Fireball():
        Skill(0, 700)
{}

void Fireball::update()
{

}

void Fireball::draw(sf::RenderWindow *window)
{

}

bool Fireball::canActivate()
{
    return !m_isActive;
}

void Fireball::activate(int targetX, int targetY)
{

}
