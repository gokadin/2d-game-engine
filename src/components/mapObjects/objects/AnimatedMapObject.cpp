#include "AnimatedMapObject.h"
#include "../../../data/IO/KeyValueReader.h"

AnimatedMapObject::AnimatedMapObject(const std::string &name, SortedRenderer *sortedRenderer, MapState *mapState):
        MapObject(name, mapState), m_counter(0), m_currentStage(0), m_box(sf::Vector2f(100, 50))
{
    loadMetadata(KeyValueReader::read(m_objectDirectory + METADATA_FILENAME));

    g = new SortedRenderGroup();
    g->addDrawable(&m_sprite);

    m_box.setFillColor(sf::Color(0, 0, 255, 100));

    g->addDrawable(&m_box);
    sortedRenderer->addGroup(g);

    updateSprite();
}

void AnimatedMapObject::update()
{
    m_counter++;
    if (m_counter == m_stageFrames)
    {
        m_counter = 0;

        m_currentStage++;
        if (m_currentStage == m_numStages - 1)
        {
            m_currentStage = 0;
        }
    }

    updateSprite();
}

void AnimatedMapObject::draw(sf::RenderWindow *window)
{
    //window->draw(m_sprite);
}

void AnimatedMapObject::updateSprite()
{
    m_sprite.setPosition(m_x - m_mapState->x() - m_spriteWidth / 2, m_y - m_mapState->y() - m_spriteHeight);
    m_sprite.setTextureRect(sf::IntRect(m_currentStage * m_spriteWidth, 0, m_spriteWidth, m_spriteHeight));

    m_box.setPosition(m_x - m_mapState->x(), m_y - m_mapState->y());

    g->setCorner(m_x - m_mapState->x(), m_y - m_mapState->y());
}

void AnimatedMapObject::loadMetadata(std::map<std::string, std::string> metadata)
{
    MapObject::loadCommonMetadata(metadata);

    m_stageFrames = Engine::UPS / std::stoi(metadata["APS"]);
    m_numStages = std::stoi(metadata["NUM_STAGES"]);
}
