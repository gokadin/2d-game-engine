#ifndef SFMLDEMO_INTERACTIONMENUENTRY_H
#define SFMLDEMO_INTERACTIONMENUENTRY_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Interaction.h"
#include "../../../utils/font/GameFonts.h"

class InteractionMenuEntry
{
public:
    InteractionMenuEntry(Interaction *interaction, GameFonts *fonts);
    ~InteractionMenuEntry();

    void draw(sf::RenderWindow *window);

    Interaction* interaction();
    float entryWidth();
    inline float x() { return m_x; }
    inline float y() { return m_y; }

    void setPosition(float x, float y);

private:
    Interaction *m_interaction;
    float m_x;
    float m_y;
    sf::Text m_text;
};

#endif //SFMLDEMO_INTERACTIONMENUENTRY_H
