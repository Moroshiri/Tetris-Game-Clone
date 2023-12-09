#include "Game.hpp"
#include <iostream>
#include <windows.h>

void Print(std::string message);
void PrintError(Error err);
void PrintErrorShort(Error err);
Size GetDesktopResolution();

int main(int argv, char** args)
{
    std::cout << "Hello it's Tetris game clone!" << std::endl;
    LPSTR dir = new CHAR[128];
    GetCurrentDirectoryA(128, dir);
    
    std::cout << "Working from: " << dir << std::endl;

    Error::PrintError = PrintErrorShort;
    Window::Print = Print;

    // -- Skalowanie okna do wielkości pulpitu --
    Size desktop = GetDesktopResolution();
    Size winSize;
    winSize.h = desktop.h < SCREEN_HEIGHT ? desktop.h * 0.9f : SCREEN_HEIGHT;
    winSize.w = winSize.h * SCREEN_RATIO;

    // -- Skalowanie klocków --
    SCREEN_SCALE = SCREEN_HEIGHT / winSize.h;
    TILE_SIZE = DEFAULT_TILE_SIZE * SCREEN_SCALE;

    Window winObj = Window(winSize, "Tetris");
    if(!winObj.Init())
    {
        PrintErrorShort(winObj.GetError());  
        return -1;
    }

    Game gameObj = Game(&winObj);
    Error runResult = gameObj.Run();

    if(runResult != Error())
        PrintErrorShort(runResult);
    
    SDL_Quit();

    return 0;
}

void Print(std::string message)
{
    std::cout << message << std::endl;
}

void PrintError(Error err)
{
    std::cout << "An error occurred while the program was running!" << std::endl;
    std::cout << "Code: " << err.GetErrorCode() << std::endl;
    std::cout << "Message: " << err.GetErrorMsg() << std::endl;
}

void PrintErrorShort(Error err)
{
    std::cout << "Error: " << err.GetErrorCode() << " : " << err.GetErrorMsg() << std::endl;
}

Size GetDesktopResolution()
{
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);
    Size res;
    res.w = desktop.right;
    res.h = desktop.bottom;

    return res;
}