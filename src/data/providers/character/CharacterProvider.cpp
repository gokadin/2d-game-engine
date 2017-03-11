#include "CharacterProvider.h"

CharacterProvider::CharacterProvider(GameState &state, SaveReader &saveReader):
        Provider(state, saveReader)
{}

void CharacterProvider::load()
{
    state.character.isMovingUp = false;
    state.character.isMovingDown = false;
    state.character.isMovingRight = false;
    state.character.isMovingLeft = false;
    state.character.boxWidth = 10;
    state.character.boxHeight = 10;
    state.character.moveSpeed = 3;
}
