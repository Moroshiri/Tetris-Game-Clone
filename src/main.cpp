#include "Game.hpp"
#include <iostream>

void Print(std::string message);

int main(int argv, char** args)
{
    std::cout << "Hello it's Tetris game clone!" << std::endl;

    Window winObj = Window();
    winObj.Init();
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