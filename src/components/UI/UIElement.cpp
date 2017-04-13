#include "UIElement.h"

UIElement::UIElement()
        : UIElement(0, 0, 0, 0)
{}

UIElement::UIElement(int x, int y, int width, int height)
        : m_x(x),
          m_y(y),
          m_width(width),
          m_height(height),
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

bool UIElement::isMouseOnUI(int x, int y)
{
    return x >= m_x && x <= m_x + m_width && y >= m_y && y <= m_y + m_height;
}
