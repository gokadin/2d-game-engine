#include "DataProvider.h"
#include "IO/KeyValueReader.h"
#include "../core/Engine.h"
#include "IO/ArrayReader.h"

void DataProvider::loadMap(Map *map)
{
    map->graphics()->loadTexture("../src/storage/game/maps/act1/town/texture.png");
    map->graphics()->setSpriteWidth(3200);
    map->graphics()->setSpriteHeight(3200);
    map->graphics()->setSpriteOffsetX(0);
    map->graphics()->setSpriteOffsetY(0);
    map->graphics()->setTileRadius(16);
    map->graphics()->setCollisionNoSlideAngleRad(0.4f);

    std::map<std::string, std::string> metadata = KeyValueReader::read("../src/storage/game/maps/act1/town/metadata");

    map->state()->setX(std::stoi(metadata["INITIAL_CX"]) - Engine::HALF_SCREEN_WIDTH);
    map->state()->setY(std::stoi(metadata["INITIAL_CY"]) - Engine::HALF_SCREEN_HEIGHT);

    map->data()->setBounds(ArrayReader::read2D("../src/storage/game/maps/act1/town/bounds"));
}

void DataProvider::loadCharacter(Character *character)
{
    character->graphics()->loadTexture("../src/storage/game/character/texture.png");
    character->graphics()->setSpriteOffsetX(0);
    character->graphics()->setSpriteOffsetY(0);
    character->graphics()->setSpriteWidth(56);
    character->graphics()->setSpriteHeight(112);
    character->graphics()->setHitBoxWidth(32);
    character->graphics()->setHitBoxHeight(128);
    character->graphics()->setCollisionRadius(32);
}

void DataProvider::loadSkills(SkillManager *skillManager)
{
    skillManager->assign(0, skill_names::FIREBALL);
}
