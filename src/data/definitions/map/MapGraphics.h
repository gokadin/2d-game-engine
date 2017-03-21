#ifndef SFMLDEMO_MAPGRAPHICS_H
#define SFMLDEMO_MAPGRAPHICS_H

#include "../Graphics.h"

class MapGraphics : public Graphics
{
public:
    inline float collisionNoSlideAngleRad() { return m_collisionNoSlideAngleRad; };

    inline void setCollisionNoSlideAngleRad(float angleRad) { m_collisionNoSlideAngleRad = angleRad; }

private:
    float m_collisionNoSlideAngleRad;
};

#endif //SFMLDEMO_MAPGRAPHICS_H
