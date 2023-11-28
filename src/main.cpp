#include "Game.hpp"
#include <iostream>
#include <windows.h>

void Print(std::string message);

int main(int argv, char** args)
{
    std::cout << "Hello it's Tetris game clone!" << std::endl;
    LPSTR dir = new CHAR[128];
    GetCurrentDirectoryA(128, dir);
    std::cout << "Working from: " << dir << std::endl;

    Window winObj = Window();
    if(!winObj.Init())
    {
        Print(winObj.GetErrorMsg());     
        return -1;
    }
    winObj.Print = (printHandle)Print;

    Game gameObj = Game(&winObj);
    gameObj.Run();
    
    SDL_Quit();

    return 0;
}

void Print(std::string message)
{
    std::cout << message << std::endl;
}