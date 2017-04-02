#ifndef SFMLDEMO_INTERACTIONMANAGER_H
#define SFMLDEMO_INTERACTIONMANAGER_H

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "dialogues/Dialogue.h"
#include "InteractionMenuEntry.h"

#define BORDER_COLOR sf::Color(183, 167, 102)
#define BACKGROUND_COLOR sf::Color(0, 0, 0, 200)

class InteractionManager
{
public:
    InteractionManager(GameFonts *fonts);
    ~InteractionManager();

    void update();
    void draw(sf::RenderWindow *window);
    void addStoryDialogue(Dialogue *dialogue);
    void open();
    void close();

private:
    const int MENU_ROW_HEIGHT = 30;
    const int MENU_ROW_PADDING_Y = 5;
    const int MENU_MIN_WIDTH = 10;
    const int MENU_TOP_MARGIN = 100;
    const int MENU_PADDING = 20;

    GameFonts *m_fonts;
    bool m_isOpen;
    sf::RectangleShape m_mainBox;
    std::vector<InteractionMenuEntry *> m_storyDialogues;

    void buildMenu();
    float buildStoryDialoguesSection();
    void centerMenu(float longestWidth);
};

#endif //SFMLDEMO_INTERACTIONMANAGER_H
