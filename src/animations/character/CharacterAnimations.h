#ifndef SFMLDEMO_CHARACTERANIMATIONS_H
#define SFMLDEMO_CHARACTERANIMATIONS_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include "../../enums/animationTypes/CharacterAnimationType.h"
#include "../Animation.h"
#include "../../data/definitions/character/CharacterGraphics.h"
#include "../../data/definitions/character/CharacterState.h"
#include "../../components/character/equipment/EquipmentManager.h"

class CharacterAnimations
{
public:
    CharacterAnimations(CharacterState *state, CharacterGraphics *graphics, EquipmentManager *equipmentManager);
    ~CharacterAnimations();

    void update();
    Animation& get(character_animation_type type);

private:
    std::map<character_animation_type, Animation *> m_animations;
    CharacterState *m_state;
    CharacterGraphics *m_graphics;
    EquipmentManager *m_equipmentManager;
};

#endif //SFMLDEMO_CHARACTERANIMATIONS_H
