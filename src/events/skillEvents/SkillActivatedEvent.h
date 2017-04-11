#ifndef SFMLDEMO_SKILLACTIVATEDEVENT_H
#define SFMLDEMO_SKILLACTIVATEDEVENT_H

#include "../../utils/Event.h"
#include "../../skills/Skill.h"

class SkillActivatedEvent : public Event
{
public:
    SkillActivatedEvent(Skill *skill):
            Event(event_type::SKILL_ACTIVATED), m_skill(skill)
    {}

    inline Skill* skill() { return m_skill; }

private:
    Skill *m_skill;
};

#endif //SFMLDEMO_SKILLACTIVATEDEVENT_H
