#pragma once
#include <windows.h>

enum GameStates
{

    GameLoop = 1,
    NewGame  = 2,
    ExitGame = 3,

};

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