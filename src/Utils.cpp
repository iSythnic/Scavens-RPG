#include "Utils.hpp"

bool LeftButtonPress()
{
    if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
        return true;
    
    return false;
}

bool RightButtonPress()
{
    if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
        return true;
    
    return false;
}

bool EscapePress()
{
    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
        return true;
    
    return false;
}