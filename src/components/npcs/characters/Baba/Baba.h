#ifndef SFMLDEMO_BABA_H
#define SFMLDEMO_BABA_H

#include "../NPC.h"

class Baba : public NPC
{
public:
    Baba(MapState *mapState, GameFonts *fonts);

    void buildInteractions();
    void update();
    void draw(sf::RenderWindow *window);

private:
    void updateSprite();
};

#endif //SFMLDEMO_BABA_H
