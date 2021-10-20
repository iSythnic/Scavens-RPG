#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <SythConsole.h>
#include "Utils.hpp"
#include "Button.hpp"
#include "Player.hpp"

class Scavens : public Syth::consoleWindow
{
    public:

        void start();

    private:
        bool importMap(const std::string &fname);
        int menu();
        void gameLoop();
        void newGameLoop();

    private:

        Player m_Player;
        
};