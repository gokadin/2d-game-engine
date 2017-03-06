#ifndef SFMLDEMO_TOWN_H
#define SFMLDEMO_TOWN_H

#include <SFML/Graphics/CircleShape.hpp>
#include "../Map.h"

class Town : public Map
{
public:
    Town();
    ~Town();

    void draw(sf::RenderWindow *window);
};

#endif //SFMLDEMO_TOWN_H
