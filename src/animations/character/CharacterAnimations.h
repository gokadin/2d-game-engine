#ifndef SFMLDEMO_CHARACTERANIMATIONS_H
#define SFMLDEMO_CHARACTERANIMATIONS_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include "../../enums/animationTypes/CharacterAnimationType.h"
#include "../Animation.h"

class CharacterAnimations
{
public:
    CharacterAnimations();
    ~CharacterAnimations();

    void update();
    void trigger(character_animation_type type);

private:
    std::map<character_animation_type, Animation *> animations;
};

#endif //SFMLDEMO_CHARACTERANIMATIONS_H
