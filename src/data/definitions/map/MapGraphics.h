#ifndef SFMLDEMO_MAPGRAPHICS_H
#define SFMLDEMO_MAPGRAPHICS_H

#include "../Graphics.h"

class MapGraphics : public Graphics
{
public:
    inline int tileRadius() { return m_tileRadius; }
    inline float collisionNoSlideAngleRad() { return m_collisionNoSlideAngleRad; };

    inline void setTileRadius(int tileRadius) { m_tileRadius = tileRadius; }
    inline void setCollisionNoSlideAngleRad(float angleRad) { m_collisionNoSlideAngleRad = angleRad; }

private:
    int m_tileRadius;
    float m_collisionNoSlideAngleRad;
};

#endif //SFMLDEMO_MAPGRAPHICS_H
