#ifndef SFMLDEMO_QUESTTRACKERUI_H
#define SFMLDEMO_QUESTTRACKERUI_H

#include <SFML/Graphics/Text.hpp>
#include "../UIElement.h"
#include "../../quests/tracking/QuestTracker.h"
#include "../../../core/Engine.h"
#include "../../../utils/observable/Observer.h"

class QuestTrackerUI : public UIElement, public Observer
{
public:
    QuestTrackerUI(GameFonts *fonts, QuestTracker *questTracker);

    void processEvent(sf::Event &event);
    void update();
    void draw(sf::RenderWindow *window);
    bool isMouseOnUI(int x, int y);
    void handleEvent(std::shared_ptr<Event> event);

private:
    const int WIDTH = 200;
    const int START_X = Engine::SCREEN_WIDTH - WIDTH;
    const int START_Y = 400;

    const std::string MAIN_TITLE_STRING = "Quests";
    const sf::Color MAIN_TITLE_COLOR = sf::Color::Cyan;

    GameFonts *m_fonts;
    QuestTracker *m_tracker;
    sf::Text m_mainTitle;
    sf::Text m_questTitle;
    sf::Text m_objectiveCounterText;
    sf::Text m_objectiveDescriptionText;

    void handleQuestAdded(Quest *quest);
    void handleObjectiveUpdated();
    void updateObjectives();
};

#endif //SFMLDEMO_QUESTTRACKERUI_H
