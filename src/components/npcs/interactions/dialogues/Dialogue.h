#ifndef SFMLDEMO_DIALOGUE_H
#define SFMLDEMO_DIALOGUE_H

#include <string>
#include "../Interaction.h"

class Dialogue : public Interaction
{
public:
    Dialogue(std::string title);

    std::string text() { return m_text; }

protected:
    std::string m_text;
};

#endif //SFMLDEMO_DIALOGUE_H
