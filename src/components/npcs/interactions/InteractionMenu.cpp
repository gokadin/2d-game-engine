#include "InteractionMenu.h"
#include "../../../core/Engine.h"

InteractionMenu::InteractionMenu(GameFonts *fonts)
        : m_mainBox(sf::Vector2f(MENU_MIN_WIDTH, 0)),
          m_fonts(fonts)
{
    m_mainBox.setOutlineThickness(3);
    m_mainBox.setOutlineColor(BORDER_COLOR);
    m_mainBox.setFillColor(BACKGROUND_COLOR);
}

InteractionMenu::~InteractionMenu()
{
    for (auto *entry : m_storyDialogues)
    {
        delete entry;
    }
    m_storyDialogues.clear();
}

void InteractionMenu::processEvent(sf::Event &event)
{
    for (auto *dialogueEntry : m_storyDialogues)
    {
        if (dialogueEntry->processEvent(event))
        {
            return;
        }
    }
}

void InteractionMenu::draw(sf::RenderWindow *window)
{
    window->draw(m_mainBox);

    for (auto *dialogueEntry : m_storyDialogues)
    {
        dialogueEntry->draw(window);
    }
}

void InteractionMenu::update()
{
    // hover logic
}

bool InteractionMenu::isMouseOnMenu(int x, int y)
{
    return x >= m_mainBox.getPosition().x && x <= m_mainBox.getPosition().x + m_mainBox.getSize().x &&
           y >= m_mainBox.getPosition().y && y <= m_mainBox.getPosition().y + m_mainBox.getSize().y;
}

void InteractionMenu::addStoryDialogue(int id, std::string title)
{
    auto entry = new InteractionMenuEntry(id, title, m_fonts);
    entry->subscribe(this);
    m_storyDialogues.push_back(entry);
    buildMenu();
}

void InteractionMenu::handleEvent(std::shared_ptr<Event> event)
{
    switch (event->type())
    {
        case event_type::INTERACTION_MENU_ENTRY_CLICKED:
            notifyObservers(event);
            break;
    }
}

void InteractionMenu::buildMenu()
{
    float longestWidth = findLongestEntry();
    m_mainBox.setPosition(Engine::CX - longestWidth / 2, MENU_TOP_MARGIN);
    m_mainBox.setSize(sf::Vector2f(longestWidth, 0.0f));

    buildStoryDialoguesSection();
}

float InteractionMenu::findLongestEntry()
{
    float longestWidth = 0.0f;
    for (auto *dialogueEntry : m_storyDialogues)
    {
        if (dialogueEntry->textWidthWithPadding() > longestWidth)
        {
            longestWidth = dialogueEntry->textWidthWithPadding();
        }
    }

    return longestWidth;
}

void InteractionMenu::buildStoryDialoguesSection()
{
    for (auto *dialogueEntry : m_storyDialogues)
    {
        dialogueEntry->setWidth(m_mainBox.getSize().x);
        dialogueEntry->setPosition(m_mainBox.getPosition().x, m_mainBox.getPosition().y);

        m_mainBox.setSize(sf::Vector2f(m_mainBox.getSize().x, m_mainBox.getSize().y + dialogueEntry->height()));
    }
}
