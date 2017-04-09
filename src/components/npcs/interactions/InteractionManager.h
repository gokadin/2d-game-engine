#ifndef SFMLDEMO_INTERACTIONMANAGER_H
#define SFMLDEMO_INTERACTIONMANAGER_H

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "dialogues/Dialogue.h"
#include "InteractionMenuEntry.h"
#include "../../../enums/npcs/InteractionType.h"
#include "InteractionMenu.h"

class InteractionManager : public Observer
{
public:
    InteractionManager(GameFonts *fonts);
    ~InteractionManager();

    void processEvent(sf::Event& event);
    void update();
    void draw(sf::RenderWindow *window);
    void notify(std::shared_ptr<Event> event);
    bool isMouseOnInteraction(int x, int y);
    void addStoryDialogue(Dialogue *dialogue);
    void reset();

private:
    GameFonts *m_fonts;
    std::vector<Interaction *> m_interactions;
    InteractionMenu m_menu;
    Interaction *m_interactionInProgress;

    void handleInteractionMenuEntryClicked(int id);
};

#endif //SFMLDEMO_INTERACTIONMANAGER_H
