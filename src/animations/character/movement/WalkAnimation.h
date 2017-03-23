#ifndef SFMLDEMO_WALKINGANIMATION_H
#define SFMLDEMO_WALKINGANIMATION_H

#include "../../Animation.h"
#include "../../../data/definitions/character/CharacterGraphics.h"
#include "../../../data/definitions/character/CharacterState.h"
#include "../../../components/character/equipment/EquipmentManager.h"

class WalkAnimation : public Animation
{
public:
    WalkAnimation(CharacterGraphics *graphics, CharacterState *state, EquipmentManager *equipmentManager);

    void update();
    void stop();
    void start();

private:
    const int APS = 6;
    const int SPRITE_POS_Y = 1;
    const int NUM_STAGES = 2;

    CharacterGraphics *m_graphics;
    CharacterState *m_state;
    EquipmentManager *m_equipmentManager;

    void updateSprite();
};

#endif //SFMLDEMO_WALKINGANIMATION_H
