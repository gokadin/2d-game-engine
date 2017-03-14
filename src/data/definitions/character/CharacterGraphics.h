#ifndef SFMLDEMO_CHARACTERGRAPHICS_H
#define SFMLDEMO_CHARACTERGRAPHICS_H

#include "../Graphics.h"

class CharacterGraphics : public Graphics
{
public:
    inline int boxWidth() { return m_boxWidth; }
    inline int boxHeight() { return m_boxHeight; }
    inline int legRoom() { return m_legRoom; }

    inline void setBoxWidth(int width) { m_boxWidth = width; }
    inline void setBoxHeight(int height) { m_boxHeight = height; }
    inline void setLegRoom(int legRoom) { m_legRoom = legRoom; }

private:
    int m_boxWidth;
    int m_boxHeight;
    int m_legRoom;
};

#endif //SFMLDEMO_CHARACTERGRAPHICS_H
