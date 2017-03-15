#ifndef SFMLDEMO_STATE_H
#define SFMLDEMO_STATE_H

class State
{
public:
    inline float x() { return m_x; }
    inline float y() { return m_y; }

    inline void setX(float x) { m_x = x; }
    inline void setY(float y) { m_y = y; }

protected:
    float m_x;
    float m_y;
};

#endif //SFMLDEMO_STATE_H
