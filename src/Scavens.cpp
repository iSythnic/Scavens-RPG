#include "Scavens.hpp"

void Scavens::start()
{
    switch (menu())
    {
        //Game starting corresponds with the return value of 1
        case GameStates::GameLoop:
            gameLoop();
            break;
            

        //New game corresponds with the return value of 2
        case GameStates::NewGame:
            newGameLoop();
            break;

        //Exit game corresonds with the return value of 3
        case GameStates::ExitGame:
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
        if (EscapePress())
            break;
        
        update();
        clear();
    }
    
}

void Scavens::newGameLoop()
{
    while (true)
    {
        drawString(1,1, L"GameNewLoop", Syth::COLOUR::FG_WHITE);
        if (EscapePress())
            break;
        
        update();
        clear();
    }
    
}

int Scavens::menu()
{

    Button gameStartButton {{33,32}, {60,41}};
    Button newGameButton   {{33,48}, {60,57}};
    Button exitGameButton  {{33,64}, {60,73}};

    while (true)
    {
        if (importMap("menu.smap"))
        {
            MakeError(L"menu file was not found");
            return 1;
        }

        updateInputEvents();

        if (gameStartButton.MouseHover({m_MouseX, m_MouseY}))
        {
            drawLine({33, 43}, {61, 43}, ' ', Syth::BG_RED);
            if (gameStartButton.MousePress({m_MouseX, m_MouseY}))
                return GameStates::GameLoop;
        }
        else if (newGameButton.MouseHover({m_MouseX, m_MouseY}))
        {
            drawLine({33,59}, {61, 59}, ' ', Syth::BG_RED);

            if (newGameButton.MousePress({m_MouseX, m_MouseY}))
                return GameStates::NewGame;
        }
        else if (exitGameButton.MouseHover({m_MouseX, m_MouseY}))
        {
            drawLine({33, 75}, {61, 75}, ' ', Syth::BG_RED);
            
            if (exitGameButton.MousePress({m_MouseX, m_MouseY}))
                return GameStates::ExitGame;
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