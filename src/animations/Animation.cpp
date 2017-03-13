#include "Animation.h"

Animation::Animation(bool isAlwaysOn):
        m_isAlwaysOn(isAlwaysOn),
        m_counter(0),
        m_isActive(false),
        m_stage(0)
{}
