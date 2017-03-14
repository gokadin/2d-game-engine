#ifndef SFMLDEMO_ANIMATION_H
#define SFMLDEMO_ANIMATION_H

class Animation
{
public:
    Animation(bool isAlwaysOn);

    virtual void update() = 0;
    virtual void stop() = 0;

    inline bool isActive() { return m_isActive; }
    inline bool isAlwaysOn() { return m_isAlwaysOn; }

protected:
    int m_counter;
    bool m_isActive;
    int m_stage;

private:
    bool m_isAlwaysOn;
};

#endif //SFMLDEMO_ANIMATION_H
