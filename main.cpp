#include "Scavens.hpp"
#include <iostream>
#include <SythConsole.h>
#include "Vector2D.hpp"

int main()
{
    Scavens game;
    game.ConstructConsole(100,100,8,8,L"Scavens");
    game.start();
}