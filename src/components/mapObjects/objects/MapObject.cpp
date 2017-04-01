#include <iostream>
#include "MapObject.h"
#include "../../../data/IO/KeyValueReader.h"

MapObject::MapObject(std::string name, MapState *mapState):
        m_mapState(mapState)
{
    m_objectDirectory = getObjectDirectory(name);

    loadTexture(m_objectDirectory + TEXTURE_FILENAME);
}

std::string MapObject::getObjectDirectory(std::string objectName)
{
    return MAP_OBJECTS_DIRECTORY + objectName + "/";
}

void MapObject::loadTexture(std::string texturePath)
{
    if (!m_texture.loadFromFile(texturePath))
    {
        std::cout << "Could not load texture." << std::endl;
    }

    m_sprite.setTexture(m_texture);
}

void MapObject::loadCommonMetadata(std::map<std::string, std::string> metadata)
{
    m_spriteWidth = std::stoi(metadata["SPRITE_WIDTH"]);
    m_spriteHeight = std::stoi(metadata["SPRITE_HEIGHT"]);
    m_x = std::stoi(metadata["INITIAL_X"]);
    m_y = std::stoi(metadata["INITIAL_Y"]);
}
