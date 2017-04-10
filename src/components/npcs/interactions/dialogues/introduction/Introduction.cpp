#include "Introduction.h"

Introduction::Introduction(GameFonts *fonts):
        Dialogue("Introduction", fonts, quest_name::INTRO_QUEST)
{
    m_text = "hello there";
}
