#ifndef SFMLDEMO_QUESTTRACKER_H
#define SFMLDEMO_QUESTTRACKER_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../../../utils/font/GameFonts.h"

class QuestTracker
{
public:
    QuestTracker(GameFonts *fonts);

    void processEvent(sf::Event &event);
    void draw(sf::RenderWindow *window);
    void update();

private:
    GameFonts *m_fonts;
};

#endif //SFMLDEMO_QUESTTRACKER_H
