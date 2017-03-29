#ifndef SFMLDEMO_MORTALENTITY_H
#define SFMLDEMO_MORTALENTITY_H

class MortalEntity
{
public:
    MortalEntity():
            m_maxLife(0), m_currentLife(0)
    {}

    inline int maxLife() { return m_maxLife; }
    inline int currentLife() { return m_currentLife; }

    inline void setMaxLife(int maxLife) { m_maxLife = maxLife; }
    inline void setCurrentLife(int currentLife) { m_currentLife = currentLife; }
    virtual void inflictDamage(int damage) = 0;

protected:
    int m_maxLife;
    int m_currentLife;
};

#endif //SFMLDEMO_MORTALENTITY_H
