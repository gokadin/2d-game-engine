#ifndef SFMLDEMO_MAP_H
#define SFMLDEMO_MAP_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../windows/Context.h"
#include "../utils/Observer.h"
#include "../core/Actions.h"

class Map : public Context, public Observer
{
public:
    Map(Actions *actions, MapState *mapState);
    virtual ~Map();

    void update();
    void draw(sf::RenderWindow *window);

protected:
    MapState *mapState;

private:
    sf::Sprite sprite;
    sf::Texture texture;
    int initialX;
    int initialY;
    int offsetX;
    int offsetY;

    void notify(Event *event);

    void handleMoveUp();
    void handleMoveDown();
    void handleMoveRight();;
    void handleMoveLeft();

    void updateMapPosition();
};

#endif //SFMLDEMO_MAP_H
