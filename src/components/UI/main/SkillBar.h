#ifndef SFMLDEMO_SKILLBAR_H
#define SFMLDEMO_SKILLBAR_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../UIElement.h"
#include "../../../utils/Observer.h"
#include "ExpBar.h"

class SkillBar : public UIElement, public Observer
{
public:
    SkillBar(GameFonts *fonts);

    void processEvent(sf::Event &event);
    void update();
    void draw(sf::RenderWindow *window);
    void notify(std::shared_ptr<Event> event);
    void handleCharacterExperienceGained();

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    ExpBar m_expBar;
};

#endif //SFMLDEMO_SKILLBAR_H
