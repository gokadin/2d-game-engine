#ifndef SFMLDEMO_STATE_H
#define SFMLDEMO_STATE_H

class State
{
public:
    inline int x() { return m_x; }
    inline int y() { return m_y; }

    inline void setX(int x) { m_x = x; }
    inline void setY(int y) { m_y = y; }

protected:
    int m_x;
    int m_y;
};

#endif //SFMLDEMO_STATE_H
