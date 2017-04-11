#ifndef SFMLDEMO_NPCS_H
#define SFMLDEMO_NPCS_H

#include "../../core/GameComponent.h"
#include "../../data/definitions/map/MapState.h"
#include "characters/NPC.h"
#include "../../utils/font/GameFonts.h"

class NPCs : public GameComponent, public Observable, public Observer
{
public:
    NPCs(MapState *mapState, GameFonts *fonts);
    ~NPCs();

    void processMouseButtonPressed(sf::Event& event);
    void processInteractionEvent(sf::Event& event);
    void update();
    void draw(sf::RenderWindow *window);
    bool isMouseOnInteraction(int x, int y);
    void notify(std::shared_ptr<Event> event);

private:
    MapState *m_mapState;
    GameFonts *m_fonts;
    std::vector<NPC *> m_npcs;
    NPC *m_currentMouseOverNPCInteraction;
};

#endif //SFMLDEMO_NPCS_H
