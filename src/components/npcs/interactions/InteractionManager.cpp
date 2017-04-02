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
    m_mainBox.setPosition(Engine::CX, MENU_TOP_MARGIN);

    float longuestWidth = 0.0f;
    float width = buildStoryDialoguesSection();
    if (width > longuestWidth)
    {
        longuestWidth = width;
    }

    centerMenu(longuestWidth);
}

float InteractionManager::buildStoryDialoguesSection()
{
    if (m_storyDialogues.size() == 0)
    {
        return 0.0f;
    }

    float longuestWidth = 0.0f;
    for (auto *dialogueEntry : m_storyDialogues)
    {
        m_mainBox.setSize(sf::Vector2f(m_mainBox.getSize().x, m_mainBox.getSize().y + MENU_ROW_HEIGHT));
        dialogueEntry->setPosition(m_mainBox.getPosition().x + MENU_PADDING,
                                   m_mainBox.getPosition().y + m_mainBox.getSize().y - MENU_ROW_HEIGHT + MENU_ROW_PADDING_Y);
        if (dialogueEntry->entryWidth() > longuestWidth)
        {
            longuestWidth = dialogueEntry->entryWidth();
        }
    }

    return longuestWidth;
}

void InteractionManager::centerMenu(float longuestWidth)
{
    float mainBoxWidth = longuestWidth + MENU_PADDING * 2;
    m_mainBox.setPosition(Engine::CX - mainBoxWidth / 2, m_mainBox.getPosition().y);
    m_mainBox.setSize(sf::Vector2f(mainBoxWidth, m_mainBox.getSize().y));

    for (auto *dialogueEntry : m_storyDialogues)
    {
        dialogueEntry->setPosition(m_mainBox.getPosition().x + (mainBoxWidth - dialogueEntry->entryWidth()) / 2,
                                   dialogueEntry->y());
    }
}
