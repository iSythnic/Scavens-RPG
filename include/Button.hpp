#pragma once
#include "Vector2D.hpp"
#include "Utils.hpp"

class Button
{
    public:
        Button() = delete;
        Button(const Vec2D<int> &t_TopLeftCord, const Vec2D<int> &t_BottomRightCoord);
        bool MouseHover(const Vec2D<int> &t_MousePos);
        bool MousePress(const Vec2D<int> &t_MousePos);
    
    private:

        Vec2D<int> m_TopLeftCord;
        Vec2D<int> m_BottonRightCord;

};