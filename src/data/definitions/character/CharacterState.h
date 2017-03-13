#ifndef SFMLDEMO_CHARACTERSTATE_H
#define SFMLDEMO_CHARACTERSTATE_H

class CharacterState
{
public:
    CharacterState():
            m_isMoving(false), m_isCasting(false)
    {}

    inline bool isMoving() { return m_isMoving; }
    inline bool isCasting() { return m_isCasting; }
    inline bool isMovementPaused() { return m_isMovementPaused; }

    inline void setIsMoving(bool value) { m_isMoving = value; }
    inline void setIsCasting(bool value) { m_isCasting = value; }
    inline void setMovementPaused(bool value) { m_isMovementPaused = value; }

private:
    bool m_isMoving;
    bool m_isCasting;
    bool m_isMovementPaused;
};

#endif //SFMLDEMO_CHARACTERSTATE_H
