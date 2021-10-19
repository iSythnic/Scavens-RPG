#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <SythConsole.h>

class Scavens : public Syth::consoleWindow
{
    public:

        void start();

    private:
        bool importMap(const std::string &fname);
        int menu();
        void gameLoop();
        void gameNewLoop();
};