#include "InteractionManager.h"
#include "../../../core/Engine.h"

InteractionManager::InteractionManager(GameFonts *fonts):
        m_fonts(fonts), m_mainBox(sf::Vector2f(MENU_MIN_WIDTH, 0))
{
    m_mainBox.setOutlineThickness(3);
    m_mainBox.setOutlineColor(BORDER_COLOR);
    m_mainBox.setFillColor(BACKGROUND_COLOR);
}

InteractionManager::~InteractionManager()
{
    for (auto *interaction : m_storyDialogues)
    {
        delete interaction;
    }
    m_storyDialogues.clear();
}

void InteractionManager::update()
{
    if (!m_isOpen)
    {
        return;
    }

    // hover logic
}

void InteractionManager::draw(sf::RenderWindow *window)
{
    if (!m_isOpen)
    {
        return;
    }

    window->draw(m_mainBox);
    for (auto *dialogues : m_storyDialogues)
    {
        dialogues->draw(window);
    }
}

void InteractionManager::addStoryDialogue(Dialogue *dialogue)
{
    m_storyDialogues.push_back(new InteractionMenuEntry(dialogue, m_fonts));
    buildMenu();
}

void InteractionManager::open()
{
    m_isOpen = true;
}

void InteractionManager::close()
{
    m_isOpen = false;
}

void InteractionManager::buildMenu()
{
    float longestWidth = findLongestEntry();
    m_mainBox.setPosition(Engine::CX - longestWidth / 2, MENU_TOP_MARGIN);
    m_mainBox.setSize(sf::Vector2f(longestWidth, 0.0f));

    buildStoryDialoguesSection();
}

float InteractionManager::findLongestEntry()
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

void InteractionManager::buildStoryDialoguesSection()
{
    for (auto *dialogueEntry : m_storyDialogues)
    {
        dialogueEntry->setWidth(m_mainBox.getSize().x);
        dialogueEntry->setPosition(m_mainBox.getPosition().x, m_mainBox.getPosition().y);

        m_mainBox.setSize(sf::Vector2f(m_mainBox.getSize().x, m_mainBox.getSize().y + dialogueEntry->height()));
    }
}

bool InteractionManager::isMouseOnInteraction(int x, int y)
{
    return x >= m_mainBox.getPosition().x && x <= m_mainBox.getPosition().x + m_mainBox.getSize().x &&
           y >= m_mainBox.getPosition().y && y <= m_mainBox.getPosition().y + m_mainBox.getSize().y;
}

void InteractionManager::processEvent(sf::Event &event)
{
    switch (event.type)
    {
        case sf::Event::MouseButtonPressed:
            handleMouseClick(event);
            break;
    }
}

void InteractionManager::handleMouseClick(sf::Event &event)
{
    for (auto *dialogueEntry : m_storyDialogues)
    {
        if (dialogueEntry->processEvent(event))
        {
            return;
        }
    }
}
