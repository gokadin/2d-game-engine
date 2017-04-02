#include "NPC.h"
#include "../../../data/IO/KeyValueReader.h"

NPC::NPC(std::string id, MapState *mapState, GameFonts *fonts):
        m_mapState(mapState), m_fonts(fonts), m_isActive(false), m_shouldActivate(false), m_interactionManager(fonts)
{
    auto npcDirectory = getNPCDirectory(id);

    loadTexture(npcDirectory + TEXTURE_FILENAME);
    loadMetadata(KeyValueReader::read(npcDirectory + METADATA_FILENAME));
    setUpText();
}

std::string NPC::getNPCDirectory(std::string id)
{
    return NPCS_DIRECTORY + id + "/";
}

void NPC::loadTexture(std::string texturePath)
{
    if (!m_texture.loadFromFile(texturePath))
    {
        std::cout << "Could not load texture." << std::endl;
    }

    m_sprite.setTexture(m_texture);
}

void NPC::loadMetadata(std::map<std::string, std::string> metadata)
{
    m_spriteWidth = std::stoi(metadata["SPRITE_WIDTH"]);
    m_spriteHeight = std::stoi(metadata["SPRITE_HEIGHT"]);
    m_hitBoxWidth = std::stoi(metadata["HITBOX_WIDTH"]);
    m_hitBoxHeight = std::stoi(metadata["HITBOX_HEIGHT"]);
    m_x = std::stoi(metadata["INITIAL_X"]);
    m_y = std::stoi(metadata["INITIAL_Y"]);
    m_name = metadata["NAME"];
}

void NPC::setUpText()
{
    m_text.setFont(m_fonts->getDefault());
    m_text.setColor(sf::Color::White);
    m_text.setCharacterSize(14);
}

void NPC::processMouseButtonPressed(sf::Event &event)
{
    float relX = m_x - m_mapState->x();
    float relY = m_y - m_mapState->y();
    if (event.mouseButton.x >= relX - m_hitBoxWidth / 2 && event.mouseButton.x <= relX + m_hitBoxWidth / 2 &&
        event.mouseButton.y >= relY - m_hitBoxHeight && event.mouseButton.y <= relY)
    {
        if (m_isActive)
        {
            return;
        }

        m_shouldActivate = true;

        return;
    }

    if (m_isActive)
    {
        deactivate();
    }
}

void NPC::draw(sf::RenderWindow *window)
{
    m_interactionManager.draw(window);
}

void NPC::update()
{
    m_interactionManager.update();

    if (!m_shouldActivate || m_isActive)
    {
        return;
    }

    float diffX = m_x - m_mapState->x() - Engine::CX;
    float diffY = m_y - m_mapState->y() - Engine::CY;
    float distance = std::hypotf(diffX, diffY);
    if (distance > ACTIVATE_RANGE)
    {
        return;
    }

    activate();
}

void NPC::activate()
{
    m_shouldActivate = false;
    m_isActive = true;
    m_interactionManager.open();
}

void NPC::deactivate()
{
    m_isActive = false;
    m_interactionManager.close();
}
