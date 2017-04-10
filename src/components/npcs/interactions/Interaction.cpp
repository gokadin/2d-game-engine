#include "Interaction.h"

Interaction::Interaction(interaction_type type, std::string title, GameFonts *fonts):
        m_type(type), m_title(title), m_fonts(fonts)
{}
