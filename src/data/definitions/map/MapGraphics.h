#ifndef SFMLDEMO_MAPGRAPHICS_H
#define SFMLDEMO_MAPGRAPHICS_H

#include "../Graphics.h"

class MapGraphics : public Graphics
{
public:
    inline float collisionNoSlideAngleRad() { return m_collisionNoSlideAngleRad; }
    inline int isometricOffsetX() { return m_isometricOffsetX; }

    inline void setCollisionNoSlideAngleRad(float angleRad) { m_collisionNoSlideAngleRad = angleRad; }
    inline void setIsometricOffsetX(int offset) { m_isometricOffsetX = offset; }

private:
    float m_collisionNoSlideAngleRad;
    int m_isometricOffsetX;
};

#endif //SFMLDEMO_MAPGRAPHICS_H
