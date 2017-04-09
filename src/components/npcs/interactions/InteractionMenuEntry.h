#ifndef SFMLDEMO_INTERACTIONMENUENTRY_H
#define SFMLDEMO_INTERACTIONMENUENTRY_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Interaction.h"
#include "../../../utils/font/GameFonts.h"

class InteractionMenuEntry : public Observable
{
public:
    InteractionMenuEntry(int id, std::string title, GameFonts *fonts);

    bool processEvent(sf::Event &event);
    void draw(sf::RenderWindow *window);

    inline float textWidthWithPadding() { return m_text.getLocalBounds().width + PADDING_X * 2; }
    inline float width() { return m_width; }
    inline int height() { return HEIGHT; }
    inline float x() { return m_x; }
    inline float y() { return m_y; }

    void setPosition(float x, float y);
    inline void setWidth(float width) { m_width = width; }

private:
    const int HEIGHT = 30;
    const int PADDING_Y = 5;
    const int PADDING_X = 20;

    int m_id;
    std::string m_title;
    float m_x;
    float m_y;
    float m_width;
    sf::Text m_text;

    bool isMouseOnEntry(sf::Event &event);
    void handleMouseClick(sf::Event &event);
};

#endif //SFMLDEMO_INTERACTIONMENUENTRY_H
