#ifndef SFMLDEMO_INTERACTION_H
#define SFMLDEMO_INTERACTION_H

#include <string>

class Interaction
{
public:
    Interaction(std::string title);

    std::string title() { return m_title; }

private:
    std::string m_title;
};

#endif //SFMLDEMO_INTERACTION_H
