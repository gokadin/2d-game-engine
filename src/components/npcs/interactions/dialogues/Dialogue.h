#ifndef SFMLDEMO_DIALOGUE_H
#define SFMLDEMO_DIALOGUE_H

#include <string>
#include <SFML/Graphics/RectangleShape.hpp>
#include "../Interaction.h"
#include "../../../../common/UI/Button.h"
#include "../../../../enums/quests/QuestName.h"

#define BUTTON_BORDER_COLOR sf::Color(183, 167, 102)
#define BUTTON_BACKGROUND_COLOR sf::Color(0, 0, 0, 200)

class Dialogue : public Interaction
{
public:
    Dialogue(std::string title, GameFonts *fonts);
    Dialogue(std::string title, GameFonts *fonts, quest_name questName);

    void processEvent(sf::Event &event);
    void draw(sf::RenderWindow *window);
    void update();
    bool isMouseOnInteraction(int x, int y);
    void activate();

    inline std::string text() { return m_text; }

protected:
    std::string m_text;

private:
    const int MARGIN_Y = 10;
    const int MARGIN_X = 10;
    const int BUTTON_WIDTH = 100;
    const int BUTTON_HEIGHT = 60;

    sf::RectangleShape m_mainBox;
    Button m_buttonCancel;
    Button m_buttonAccept;
    quest_name m_questName;

    void handleMouseButtonPressed(int mouseX, int mouseY);
};

#endif //SFMLDEMO_DIALOGUE_H
