#ifndef SFMLDEMO_CHARACTER_H
#define SFMLDEMO_CHARACTER_H

#include <SFML/Graphics/RenderWindow.hpp>

class Character
{
public:
    Character();
    ~Character();

    void draw(sf::RenderWindow *window);
};

#endif //SFMLDEMO_CHARACTER_H
