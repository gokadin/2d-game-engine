#include "CharacterProvider.h"

CharacterProvider::CharacterProvider(GameState &state, SaveReader &saveReader):
        Provider(state, saveReader)
{}

void CharacterProvider::load()
{
    state.character.texture = GAME_STORAGE_ROOT + "character/texture.png";
    state.character.isMovingUp = false;
    state.character.isMovingDown = false;
    state.character.isMovingRight = false;
    state.character.isMovingLeft = false;
    state.character.boxWidth = 20;
    state.character.boxHeight = 64;
    state.character.legRoom = 5;
    state.character.moveSpeed = 3;
}
