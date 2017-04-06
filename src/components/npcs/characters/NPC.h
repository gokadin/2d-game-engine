#ifndef SFMLDEMO_NPC_H
#define SFMLDEMO_NPC_H

#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../../../data/definitions/map/MapState.h"
#include "../../../utils/font/GameFonts.h"
#include "../interactions/InteractionManager.h"

class NPC
{
public:
    NPC(std::string id, MapState *mapState, GameFonts *fonts);

    virtual void buildInteractions() = 0;
    virtual void update();
    virtual void draw(sf::RenderWindow *window);

    bool isMouseOnInteraction(int x, int y);
    void processMouseButtonPressed(sf::Event &event);
    void processInteractionEvent(sf::Event& event);

    inline bool isActive() { return m_isActive; }

protected:
    MapState *m_mapState;
    GameFonts *m_fonts;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Text m_text;
    InteractionManager m_interactionManager;
    int m_spriteWidth;
    int m_spriteHeight;
    int m_hitBoxWidth;
    int m_hitBoxHeight;
    int m_x;
    int m_y;
    std::string m_name;
    bool m_isActive;
    bool m_shouldActivate;

    virtual void activate();
    virtual void deactivate();

private:
    const std::string NPCS_DIRECTORY = "../src/storage/game/npcs/";
    const std::string TEXTURE_FILENAME = "texture.png";
    const std::string METADATA_FILENAME = "metadata";
    const int ACTIVATE_RANGE = 80;

    std::string getNPCDirectory(std::string id);
    void loadTexture(std::string texturePath);
    void loadMetadata(std::map<std::string, std::string> metadata);
    void setUpText();
};

#endif //SFMLDEMO_NPC_H
