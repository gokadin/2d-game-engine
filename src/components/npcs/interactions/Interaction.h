#ifndef SFMLDEMO_INTERACTION_H
#define SFMLDEMO_INTERACTION_H

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../../../utils/Observable.h"
#include "../../../enums/npcs/InteractionType.h"
#include "../../../utils/font/GameFonts.h"

class Interaction : public Observable
{
public:
    Interaction(interaction_type type, std::string title, GameFonts *fonts);

    virtual void processEvent(sf::Event &event) = 0;
    virtual void draw(sf::RenderWindow *window) = 0;
    virtual void update() = 0;;
    virtual bool isMouseOnInteraction(int x, int y) = 0;

    std::string title() { return m_title; }
    interaction_type type() { return m_type; }

    virtual void activate() = 0;

protected:
    GameFonts *m_fonts;

private:
    interaction_type m_type;
    std::string m_title;
};

#endif //SFMLDEMO_INTERACTION_H
