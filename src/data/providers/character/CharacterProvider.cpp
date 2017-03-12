#include "CharacterProvider.h"

CharacterProvider::CharacterProvider(GameState &state, SaveReader &saveReader):
        Provider(state, saveReader)
{}

void CharacterProvider::load()
{
    state.character.texture = GAME_STORAGE_ROOT + "character/texture.png";
    state.character.spriteWidth = 56;
    state.character.spriteHeight = 112;
    state.character.spriteOffsetX = 0;
    state.character.spriteOffsetY = 0;
    state.character.isMovingUp = false;
    state.character.isMovingDown = false;
    state.character.isMovingRight = false;
    state.character.isMovingLeft = false;
    state.character.pauseMovement = false;
    state.character.boxWidth = 30;
    state.character.boxHeight = 128;
    state.character.legRoom = 5;
    state.character.moveSpeed = 3;
    SkillState skill0;
    skill0.name = skill_names::FIREBALL;
    skill0.isActive = false;
    skill0.castTimeMs = 700;
    state.character.skills.push_back(skill0);
    SkillState skill1;
    skill1.name = skill_names::NONE;
    skill1.isActive = false;
    skill1.castTimeMs = 0;
    state.character.skills.push_back(skill1);
    state.character.isCasting = false;
    state.character.castingType = casting_types::NO_CAST;
    state.character.castingSkillIndex = 0;
}