#include "UIElement.h"

UIElement::UIElement():
        m_isOpen(false)
{}

void UIElement::open()
{
    m_isOpen = true;
}

void UIElement::close()
{
    m_isOpen = false;
}

bool UIElement::isOpen()
{
    return m_isOpen;
}
