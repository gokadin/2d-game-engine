#ifndef SFMLDEMO_DIALOGUE_H
#define SFMLDEMO_DIALOGUE_H

#include <string>
#include <SFML/Graphics/RectangleShape.hpp>
#include "../Interaction.h"

class Dialogue : public Interaction
{
public:
    Dialogue(std::string title);

    void processEvent(sf::Event &event);
    void draw(sf::RenderWindow *window);
    void update();
    bool isMouseOnInteraction(int x, int y);
    void activate();

    std::string text() { return m_text; }

protected:
    std::string m_text;
    sf::RectangleShape m_mainBox;
};

#endif //SFMLDEMO_DIALOGUE_H
