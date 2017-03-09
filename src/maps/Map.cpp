#include "Map.h"

Map::Map(Actions *actions, MapState *mapState):
        mapState(mapState)
{
    actions->subscribe(this);

    if (!texture.loadFromFile("../assets/images/maps/town/sand.jpg"))
    {
        std::cout << "ERROR WITH TEXTURE" << std::endl;
    }

    sprite.setTexture(texture);
    initialX = 100;
    initialY = 100;
    offsetX = 0;
    offsetY = 0;
    sprite.setTextureRect(sf::IntRect(initialX, initialY, 1280, 720));
}

Map::~Map() {}

void Map::notify(Event *event)
{

}

void Map::update()
{
    if (mapState->getIsMovingUp())
    {
        handleMoveUp();
    }

    if (mapState->getIsMovingDown())
    {
        handleMoveDown();
    }

    if (mapState->getIsMovingRight())
    {
        handleMoveRight();
    }

    if (mapState->getIsMovingLeft())
    {
        handleMoveLeft();
    }
}

void Map::handleMoveUp()
{
    offsetY -= 10;
    updateMapPosition();
}

void Map::handleMoveDown()
{
    offsetY += 10;
    updateMapPosition();
}

void Map::handleMoveRight()
{
    offsetX += 10;
    updateMapPosition();
}

void Map::handleMoveLeft()
{
    offsetX -= 10;
    updateMapPosition();
}

void Map::updateMapPosition()
{
    sprite.setTextureRect(sf::IntRect(initialX + offsetX, initialY + offsetY, 1280, 720));
}

void Map::draw(sf::RenderWindow *window)
{
    window->draw(sprite);
}
