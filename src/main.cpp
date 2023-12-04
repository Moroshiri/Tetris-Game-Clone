#include "Game.hpp"
#include <iostream>
#include <windows.h>

void Print(std::string message);
void PrintError(Error err);
void PrintErrorShort(Error err);

const int SCREEN_WIDTH = 672;
const int SCREEN_HEIGHT = 992;

int main(int argv, char** args)
{
    std::cout << "Hello it's Tetris game clone!" << std::endl;
    LPSTR dir = new CHAR[128];
    GetCurrentDirectoryA(128, dir);
    std::cout << "Working from: " << dir << std::endl;

    Error::PrintError = PrintErrorShort;
    Window::Print = Print;

    Window winObj = Window(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris");
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