#include "NPCs.h"
#include "characters/Baba/Baba.h"

NPCs::NPCs(MapState *mapState, GameFonts *fonts):
        m_mapState(mapState), m_fonts(fonts), m_currentMouseOverNPCInteraction(nullptr)
{
    m_npcs.push_back(new Baba(m_mapState, m_fonts));
}

NPCs::~NPCs()
{
    m_currentMouseOverNPCInteraction = nullptr;

    for (auto *npc : m_npcs)
    {
        delete npc;
    }
    m_npcs.clear();
}

void NPCs::processInteractionEvent(sf::Event &event)
{
    m_currentMouseOverNPCInteraction->processInteractionEvent(event);
}

void NPCs::processMouseButtonPressed(sf::Event &event)
{
    for (auto *npc : m_npcs)
    {
        npc->processMouseButtonPressed(event);
    }
}

void NPCs::update()
{
    for (auto *npc : m_npcs)
    {
        npc->update();
    }
}

void NPCs::draw(sf::RenderWindow *window)
{
    for (auto *npc : m_npcs)
    {
        npc->draw(window);
    }
}

bool NPCs::isMouseOnInteraction(int x, int y)
{
    for (auto *npc : m_npcs)
    {
        if (npc->isActive() && npc->isMouseOnInteraction(x, y))
        {
            m_currentMouseOverNPCInteraction = npc;
            return true;
        }
    }

    return false;
}
