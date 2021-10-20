#pragma once
#include <windows.h>

enum GameStates
{

    GameLoop = 1,
    NewGame  = 2,
    ExitGame = 3,

};

bool LeftButtonPress();

bool RightButtonPress();

bool EscapePress();