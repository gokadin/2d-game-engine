#include "MonsterProvider.h"

MonsterProvider::MonsterProvider(GameState &state, SaveReader &saveReader):
        Provider(state, saveReader)
{}

void MonsterProvider::load()
{
    for (int i = 0; i < 3; i++)
    {
        MonsterState monsterState;
        monsterState.texture = GAME_STORAGE_ROOT + "monsters/common/zombie/texture.png";
        monsterState.type = monster_types::ZOMBIE;
        monsterState.boxHeight = 112;
        monsterState.boxWidth = 56;
        monsterState.spriteHeight = 112;
        monsterState.spriteWidth = 56;
        monsterState.spriteOffsetX = 0;
        monsterState.spriteOffsetY = 0;
        monsterState.legRoom = 10;

        state.monsters.push_back(monsterState);
    }

    state.monsters[0].x = 800;
    state.monsters[0].y = 1300;
    state.monsters[1].x = 900;
    state.monsters[1].y = 1400;
    state.monsters[2].x = 1200;
    state.monsters[2].y = 1350;
}
