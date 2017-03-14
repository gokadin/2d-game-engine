#include "DataProvider.h"

void DataProvider::loadMap(Map *map)
{
    map->graphics()->loadTexture("../src/storage/game/maps/act1/town/texture.png");
    map->graphics()->setSpriteWidth(3200);
    map->graphics()->setSpriteHeight(3200);
    map->graphics()->setSpriteOffsetX(0);
    map->graphics()->setSpriteOffsetY(0);

    //map->state().
}

void DataProvider::loadCharacter(Character *character)
{
    character->graphics()->loadTexture("../src/storage/game/character/texture.png");
    character->graphics()->setSpriteOffsetX(0);
    character->graphics()->setSpriteOffsetY(0);
    character->graphics()->setSpriteWidth(56);
    character->graphics()->setSpriteHeight(112);
    character->graphics()->setBoxWidth(32);
    character->graphics()->setBoxHeight(128);
    character->graphics()->setLegRoom(10);
}

void DataProvider::loadSkills(SkillManager *skillManager)
{
    skillManager->assign(0, skill_names::FIREBALL);
}
