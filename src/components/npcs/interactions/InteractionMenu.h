#ifndef SFMLDEMO_INTERACTIONMENU_H
#define SFMLDEMO_INTERACTIONMENU_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../../../utils/font/GameFonts.h"
#include "InteractionMenuEntry.h"
#include "dialogues/Dialogue.h"

#define BORDER_COLOR sf::Color(183, 167, 102)
#define BACKGROUND_COLOR sf::Color(0, 0, 0, 200)

class InteractionMenu : public Observer, public Observable
{
public:
    InteractionMenu(GameFonts *fonts);
    ~InteractionMenu();

    void processEvent(sf::Event& event);
    void draw(sf::RenderWindow *window);
    void update();
    bool isMouseOnMenu(int x, int y);
    void addStoryDialogue(int id, std::string title);
    void notify(std::shared_ptr<Event> event);

private:
    const int MENU_MIN_WIDTH = 10;
    const int MENU_TOP_MARGIN = 100;

    sf::RectangleShape m_mainBox;
    GameFonts *m_fonts;
    std::vector<InteractionMenuEntry *> m_storyDialogues;

    void buildMenu();
    float findLongestEntry();
    void buildStoryDialoguesSection();
};

#endif //SFMLDEMO_INTERACTIONMENU_H
