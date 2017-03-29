#include "PoisonNova.h"
#include "PoisonNovaProjectile.h"

PoisonNova::PoisonNova(MapState *mapState):
        ProjectileSkill(0, 700), m_mapState(mapState)
{
    if (!m_projectileTexture.loadFromFile("../src/storage/game/skills/poisonNova/texture.png"))
    {
        std::cout << "ERROR WITH TEXTURE" << std::endl;
    }

    m_baseDamage = 60;
    m_baseProjectileDamage = 60;
}

void PoisonNova::update()
{
    if (!m_isCastingAnimationFinished)
    {
        Skill::countCastAnimationTime();
    }

    ProjectileSkill::update();
}

void PoisonNova::draw(sf::RenderWindow *window)
{
    ProjectileSkill::draw(window);
}

bool PoisonNova::canActivate()
{
    return m_isCastingAnimationFinished;
}

void PoisonNova::activate(int targetX, int targetY)
{
    m_isActive = true;
    m_isCastingAnimationFinished = false;

    double angleStep = M_PI / PROJECTILES_PER_CAST * 2;
    for (int i = -PROJECTILES_PER_CAST / 2; i < PROJECTILES_PER_CAST / 2; i++)
    {
        addProjectile(new PoisonNovaProjectile(&m_projectileTexture, m_mapState, angleStep * i, m_calculatedProjectileDamage));
    }
}

void PoisonNova::handleCharacterStatsChanged(CharacterStats *characterStats)
{
    m_calculatedDamage = m_baseDamage + characterStats->spellPower();
    m_calculatedProjectileDamage = m_baseProjectileDamage + characterStats->spellPower();
}
