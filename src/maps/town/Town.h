#ifndef SFMLDEMO_TOWN_H
#define SFMLDEMO_TOWN_H

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../Map.h"

class Town : public Map
{
public:
    Town(Actions *actions);
    ~Town();

    void update(sf::Event event);
    void draw(sf::RenderWindow *window);

private:
    sf::Sprite sprite;
    sf::Texture texture;
    int a;
    int b;
    bool move;

    void notify(Event *event);
    void handleKeyPressed(sf::Keyboard::Key code);
    void handleWPressed();
};

#endif //SFMLDEMO_TOWN_H
