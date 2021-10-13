#include "Scavens.h"

void Scavens::start()
{
    switch (menu())
    {
        //Game starting corresponds with the return value of 1
        case 1:
            gameLoop();
            break;
            

        //New game corresponds with the return value of 2
        case 2:
            gameNewLoop();
            break;

        //Exit game corresonds with the return value of 3
        case 3:
            break;
        
        default:
            break;
    }
}

void Scavens::gameLoop()
{
    while (true)
    {
        drawString(1,1, L"GameLoop", Syth::COLOUR::FG_WHITE);
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
            break;
        
        update();
        clear();
    }
    
}

void Scavens::gameNewLoop()
{
    while (true)
    {
        drawString(1,1, L"GameNewLoop", Syth::COLOUR::FG_WHITE);
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
            break;
        
        update();
        clear();
    }
    
}

int Scavens::menu()
{

    while (true)
    {
        if (importMap("menu.smap"))
        {
            MakeError(L"menu file was not found");
            return 1;
        }

        updateInputEvents();

        if (m_MouseX >= 33 && m_MouseX <= 60 && m_MouseY >= 32 && m_MouseY <= 41)
        {
            drawLine({33, 43}, {61, 43}, ' ', Syth::BG_RED);
        }
        else if (m_MouseX >= 33 && m_MouseX <= 60 && m_MouseY >= 48 && m_MouseY <= 57)
        {
            drawLine({33,59}, {61, 59}, ' ', Syth::BG_RED);
        }
        else if (m_MouseX >= 33 && m_MouseX <= 60 && m_MouseY >= 64 && m_MouseY <= 73)
        {
            drawLine({33, 75}, {61, 75}, ' ', Syth::BG_RED);
        }

        if (m_MouseX >= 33 && m_MouseX <= 60 && m_MouseY >= 32 && m_MouseY <= 41 && GetAsyncKeyState(VK_LBUTTON) & 0x8000)
        {
            return 1;   // Returns the number correspodning to starting the game
        }
        else if (m_MouseX >= 33 && m_MouseX <= 60 && m_MouseY >= 48 && m_MouseY <= 57 && GetAsyncKeyState(VK_LBUTTON) & 0x8000)
        {
            return 2;  // Returns the number corresodning to starting a new game
        }
        else if (m_MouseX >= 33 && m_MouseX <= 60 && m_MouseY >= 64 && m_MouseY <= 73 && GetAsyncKeyState(VK_LBUTTON) & 0x8000)
        {
            return 3; // returns the number to exit
        }

        update();
        clear();
    }

    return 0;
}

bool Scavens::importMap(const std::string &fname)
{
    std::string AssetPath {"../assets/"+fname};
    std::ifstream inputFile {AssetPath, std::ios_base::binary};

    if (!inputFile)
        return true;
    
    for (int i {0}; i < m_ScreenWidth * m_ScreenHeight; i++)
    {
        inputFile.read((char *)&m_ScreenBuf[i], sizeof(CHAR_INFO));
    }

    inputFile.close();

    return false;
}