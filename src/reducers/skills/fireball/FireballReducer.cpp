#include "FireballReducer.h"

FireballReducer::FireballReducer(GameState &state):
        SkillReducer(state)
{}

void FireballReducer::process(int stateIndex, int targetX, int targetY)
{
    state.character.skills[stateIndex].isActive = true;

    ProjectileState projectile;
    projectile.currentX = state.config.cx;
    projectile.currentY = state.config.cy;
    projectile.targetX = targetX;
    projectile.targetY = targetY;
    projectile.phase = projectile_phases::CASTING;

    state.character.skills[stateIndex].projectiles.push_back(projectile);

    state.character.isCasting = true;
    state.character.castingType = casting_types::INSTANT_CAST;
    state.character.castingSkillIndex = stateIndex;
    state.character.pauseMovement = true;
}
