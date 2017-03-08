#ifndef SFMLDEMO_ACTIONS_H
#define SFMLDEMO_ACTIONS_H

#include <SFML/Window/Event.hpp>
#include "../utils/Observable.h"
#include "../utils/Event.h"

class Actions : public Observable
{
public:
    Actions();
    ~Actions();

    void update(sf::Event event);

private:
    bool isMovingUp;
};

enum actions {MOVE_UP, STOP};

#endif //SFMLDEMO_ACTIONS_H
