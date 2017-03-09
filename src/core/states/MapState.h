#ifndef SFMLDEMO_MAPSTATE_H
#define SFMLDEMO_MAPSTATE_H

class MapState
{
public:
    MapState()
    {
        isMovingUp = false;
        isMovingDown = false;
        isMovingRight = false;
        isMovingLeft = false;
    }

    inline bool getIsMovingUp() { return isMovingUp; }
    inline bool getIsMovingDown() { return isMovingDown; }
    inline bool getIsMovingRight() { return isMovingRight; }
    inline bool getIsMovingLeft() { return isMovingLeft; }

    inline void setIsMovingUp(bool isMovingUp) { this->isMovingUp = isMovingUp; }
    inline void setIsMovingDown(bool isMovingDown) { this->isMovingDown = isMovingDown; }
    inline void setIsMovingRight(bool isMovingRight) { this->isMovingRight = isMovingRight; }
    inline void setIsMovingLeft(bool isMovingLeft) { this->isMovingLeft = isMovingLeft; }

private:
    bool isMovingUp;
    bool isMovingDown;
    bool isMovingRight;
    bool isMovingLeft;
};

#endif //SFMLDEMO_MAPSTATE_H
