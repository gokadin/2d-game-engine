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
    state.character.boxWidth = 30;
    state.character.boxHeight = 128;
    state.character.legRoom = 5;
    state.character.moveSpeed = 3;
}
