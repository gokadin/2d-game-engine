#ifndef SFMLDEMO_CHARACTEREXPERIENCEGAINEDEVENT_H
#define SFMLDEMO_CHARACTEREXPERIENCEGAINEDEVENT_H

#include "../../utils/observable/Event.h"

class CharacterExperienceGainedEvent : public Event
{
public:
    CharacterExperienceGainedEvent(uint32_t neededExperience, uint32_t previousLevelExperience,
                                   uint32_t currentExperience)
            : Event(event_type::CHARACTER_EXPERIENCE_GAINED),
              m_levelExperience(neededExperience),
              m_previousLevelExperience(previousLevelExperience),
              m_currentExperience(currentExperience)
    {}

    inline uint32_t levelExperience() { return m_levelExperience; }
    inline uint32_t previousLevelExperience() { return m_previousLevelExperience; }
    inline uint32_t currentExperience() { return m_currentExperience; }

private:
    uint32_t m_levelExperience;
    uint32_t m_previousLevelExperience;
    uint32_t m_currentExperience;
};

#endif //SFMLDEMO_CHARACTEREXPERIENCEGAINEDEVENT_H
