#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "module/Window.hpp"
#include "time/Time.hpp"
#include "mechanics/grid/Board.hpp"
#include "mechanics/grid/TShape.hpp"

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

    Texture _frameTex;
    Sprite _frame;

    Texture** _tileTexArray;
    Board _tileBoard;
    TShape _actualShape;
    Board _nextShapeBoard;
    TShape _nextShape;

    void NextShape();
    void RefreshBoard();
};

#endif