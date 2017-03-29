#ifndef SFMLDEMO_EFFECT_H
#define SFMLDEMO_EFFECT_H

class Effect
{
public:
    Effect();

    virtual void update() = 0;

    inline bool isCompleted() { return m_isCompleted; }

protected:
    int m_counter;
    int m_frames;
    bool m_isCompleted;
};

#endif //SFMLDEMO_EFFECT_H
