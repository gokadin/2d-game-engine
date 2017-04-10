#include "Baba.h"
#include "../../interactions/dialogues/introduction/Introduction.h"

Baba::Baba(MapState *mapState, GameFonts *fonts):
        NPC("baba", mapState, fonts)
{
    updateSprite();
    buildInteractions();
}

void Baba::buildInteractions()
{
    m_interactionManager.addStoryDialogue(new Introduction(m_fonts));
}

void Baba::update()
{
    NPC::update();

    updateSprite();
}

void Baba::draw(sf::RenderWindow *window)
{
    NPC::draw(window);

    window->draw(m_sprite);
    window->draw(m_text);
}

void Baba::updateSprite()
{
    float relX = m_x - m_mapState->x();
    float relY = m_y - m_mapState->y();

    m_sprite.setPosition(relX - m_spriteWidth / 2, relY - m_spriteHeight);

    m_text.setPosition(relX - m_spriteWidth / 2, relY - m_spriteHeight);
    m_text.setString(m_name + (m_shouldActivate ? " SHOULD " : "") + (m_isActive ? " ACTIVE " : "")); // temp
}
