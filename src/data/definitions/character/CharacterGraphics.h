#ifndef SFMLDEMO_CHARACTERGRAPHICS_H
#define SFMLDEMO_CHARACTERGRAPHICS_H

#include "../Graphics.h"

class CharacterGraphics : public Graphics
{
public:
    inline int hitBoxWidth() { return m_hitBoxWidth; }
    inline int hitBoxHeight() { return m_hitBoxHeight; }
    inline int collisionRadius() { return m_collisionRadius; }

    inline void setHitBoxWidth(int width) { m_hitBoxWidth = width; }
    inline void setHitBoxHeight(int height) { m_hitBoxHeight = height; }
    inline void setCollisionRadius(int collisionRadius) { m_collisionRadius = collisionRadius; }

private:
    int m_hitBoxWidth;
    int m_hitBoxHeight;
    int m_collisionRadius;
};

#endif //SFMLDEMO_CHARACTERGRAPHICS_H
