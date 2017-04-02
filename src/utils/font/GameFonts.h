#ifndef SFMLDEMO_GAMEFONTS_H
#define SFMLDEMO_GAMEFONTS_H

#include <iostream>
#include <SFML/Graphics/Font.hpp>

class GameFonts
{
public:
    GameFonts()
    {
        if (!m_default.loadFromFile("../assets/fonts/Roboto-Regular.ttf"))
        {
            std::cout << "Could not load font." << std::endl;
        }
    }

    inline sf::Font& getDefault() { return m_default; }

private:
    sf::Font m_default;
};

#endif //SFMLDEMO_GAMEFONTS_H
