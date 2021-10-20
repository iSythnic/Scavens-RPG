#include "Button.hpp"

Button::Button(const Vec2D<int> &t_TopLeftCord, const Vec2D<int> &t_BottomRightCord) : m_TopLeftCord(t_TopLeftCord), m_BottonRightCord(t_BottomRightCord)
{}
bool Button::MouseHover(const Vec2D<int> &MousePos)
{
    if (MousePos.m_X >= m_TopLeftCord.m_X && MousePos.m_X <= m_BottonRightCord.m_X && MousePos.m_Y >= m_TopLeftCord.m_Y && MousePos.m_Y <= m_BottonRightCord.m_Y)
    {
        return true;
    }

    return false;
}

bool Button::MousePress(const Vec2D<int> &MousePos)
{
    if (MouseHover(MousePos) && LeftButtonPress())
    {
        return true;
    }

    return false;
}