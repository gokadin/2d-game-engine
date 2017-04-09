#ifndef SFMLDEMO_INTERACTION_H
#define SFMLDEMO_INTERACTION_H

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../../../utils/Observable.h"
#include "../../../enums/npcs/InteractionType.h"

class Interaction : public Observable
{
public:
    Interaction(interaction_type type, std::string title);

    virtual void processEvent(sf::Event &event) = 0;
    virtual void draw(sf::RenderWindow *window) = 0;
    virtual void update() = 0;;
    virtual bool isMouseOnInteraction(int x, int y) = 0;

    std::string title() { return m_title; }
    interaction_type type() { return m_type; }

    virtual void activate() = 0;

private:
    interaction_type m_type;
    std::string m_title;
};

#endif //SFMLDEMO_INTERACTION_H
