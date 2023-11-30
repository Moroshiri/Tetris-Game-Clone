#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "module/Window.hpp"
#include "time/Time.hpp"

class Game
{
public:
    Game(Window* window);

    // Inicjalizuje składniki
    //ool Init();

    // Uruchamia pętlę główną
    Error Run();

    // Kończy działanie pętli głównej
    void End();

    void HandleEvents();

    void KeyboardInput(SDL_Keycode key_code);

private:
    Window* _win;
    Time _time;
    const Uint8* _keyState;

    bool _running;
    
};

#endif