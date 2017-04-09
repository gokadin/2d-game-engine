#include "InteractionManager.h"
#include "../../../core/Engine.h"
#include "../../../events/npcEvents/InteractionMenuEntryClickedEvent.h"

InteractionManager::InteractionManager(GameFonts *fonts):
        m_fonts(fonts), m_menu(fonts), m_interactionInProgress(nullptr)
{
    m_menu.subscribe(this);
}

InteractionManager::~InteractionManager()
{
    m_interactionInProgress = nullptr;

    for (auto *interaction : m_interactions)
    {
        delete interaction;
    }
    m_interactions.clear();
}

void InteractionManager::processEvent(sf::Event &event)
{
    if (m_interactionInProgress == nullptr)
    {
        m_menu.processEvent(event);
        return;
    }

    m_interactionInProgress->processEvent(event);
}

void InteractionManager::update()
{
    if (m_interactionInProgress == nullptr)
    {
        m_menu.update();
        return;
    }

    m_interactionInProgress->update();
}

void InteractionManager::draw(sf::RenderWindow *window)
{
    if (m_interactionInProgress == nullptr)
    {
        m_menu.draw(window);
        return;
    }

    m_interactionInProgress->draw(window);
}

void InteractionManager::notify(std::shared_ptr<Event> event)
{
    switch (event->type())
    {
        case event_type::INTERACTION_MENU_ENTRY_CLICKED:
            handleInteractionMenuEntryClicked(std::static_pointer_cast<InteractionMenuEntryClickedEvent>(event)->id());
            break;
    }
}

void InteractionManager::addStoryDialogue(Dialogue *dialogue)
{
    m_menu.addStoryDialogue((int)m_interactions.size(), dialogue->title());
    m_interactions.push_back((Interaction *&&)dialogue);
}

bool InteractionManager::isMouseOnInteraction(int x, int y)
{
    if (m_interactionInProgress == nullptr)
    {
        return m_menu.isMouseOnMenu(x, y);
    }

    return m_interactionInProgress->isMouseOnInteraction(x, y);
}

void InteractionManager::reset()
{
    m_interactionInProgress = nullptr;
}

void InteractionManager::handleInteractionMenuEntryClicked(int id)
{
    m_interactionInProgress = m_interactions[id];
    m_interactions[id]->activate();
}
