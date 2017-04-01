#ifndef SFMLDEMO_MAPOBJECT_H
#define SFMLDEMO_MAPOBJECT_H

#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../../../data/definitions/map/MapState.h"

class MapObject
{
public:
    MapObject(std::string name, MapState *mapState);

    virtual void update() = 0;
    virtual void draw(sf::RenderWindow *window) = 0;

protected:
    const std::string METADATA_FILENAME = "metadata";

    std::string m_objectDirectory;
    int m_spriteWidth;
    int m_spriteHeight;
    int m_x;
    int m_y;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    MapState *m_mapState;

    virtual void loadMetadata(std::map<std::string, std::string> metadata) = 0;

    void loadCommonMetadata(std::map<std::string, std::string> metadata);

private:
    const std::string MAP_OBJECTS_DIRECTORY = "../src/storage/game/mapObjects/";
    const std::string TEXTURE_FILENAME = "texture.png";

    std::string getObjectDirectory(std::string objectName);
    void loadTexture(std::string texturePath);
};

#endif //SFMLDEMO_MAPOBJECT_H
