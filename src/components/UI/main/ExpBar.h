#ifndef SFMLDEMO_EXPBAR_H
#define SFMLDEMO_EXPBAR_H

#include <SFML/Graphics/RectangleShape.hpp>
#include "../UIElement.h"
#include "../../../utils/font/GameFonts.h"

class ExpBar : public UIElement
{
public:
    ExpBar(GameFonts *fonts, int skillBarX, int skillBarY, int skillBarWidth);

    void processEvent(sf::Event &event);
    void update();
    void draw(sf::RenderWindow *window);
    void handleCharacterExperienceGained();

private:
    const int HEIGHT = 10;

    GameFonts *m_fonts;
    sf::RectangleShape m_expBar;
    sf::RectangleShape m_expBarProgress;
};

#endif //SFMLDEMO_EXPBAR_H
