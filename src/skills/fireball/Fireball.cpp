#include <iostream>
#include "Fireball.h"
#include "FireballProjectile.h"

Fireball::Fireball(MapState *mapState):
        ProjectileSkill(0, 700), m_mapState(mapState)
{
    if (!m_projectileTexture.loadFromFile("../src/storage/game/skills/fireball/texture.png"))
    {
        std::cout << "ERROR WITH TEXTURE" << std::endl;
    }

    m_damage = 60;
    m_projectileDamage = 60;
}

void Fireball::update()
{
    if (!m_isCastingAnimationFinished)
    {
        Skill::countCastAnimationTime();
    }

    ProjectileSkill::update();
}

void Fireball::draw(sf::RenderWindow *window)
{
    ProjectileSkill::draw(window);
}

bool Fireball::canActivate()
{
    return m_isCastingAnimationFinished;
}

void Fireball::activate(int targetX, int targetY)
{
    m_isActive = true;
    m_isCastingAnimationFinished = false;
    addProjectile(new FireballProjectile(&m_projectileTexture, m_mapState, targetX, targetY, m_projectileDamage));
}
