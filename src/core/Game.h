#ifndef SFMLDEMO_GAME_H
#define SFMLDEMO_GAME_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../data/DataProvider.h"
#include "../components/character/Character.h"
#include "../components/skills/SkillManager.h"
#include "../components/map/Map.h"
#include "../components/monsters/Monsters.h"
#include "../components/UI/UserInterface.h"
#include "../components/mapObjects/MapObjects.h"
#include "../components/npcs/NPCs.h"
#include "../components/quests/Quests.h"
#include "../utils/font/GameFonts.h"

class Game
{
public:
    Game(sf::RenderWindow *window, GameFonts *fonts);
    ~Game();

    void processEvent(sf::Event &event);
    void update();
    void draw();

private:
    sf::RenderWindow *m_window;
    GameFonts *m_fonts;
    DataProvider *m_dataProvider;
    Map *m_map;
    Character *m_character;
    SkillManager *m_skillManager;
    Monsters *m_monsters;
    UserInterface *m_userInterface;
    MapObjects *m_mapObjects;
    NPCs *m_npcs;
    Quests *m_quests;

    bool m_mousePressWasOnUI;
    bool m_mousePressWasOnInteraction;

    void load();
    void subscribeComponents();
};

#endif //SFMLDEMO_GAME_H
