#include "Game.hpp"

#include "util/Convert.hpp"

Game::Game(Window* window) : _keyState(SDL_GetKeyboardState(NULL))
{
    _win = window;
}

void Game::End()
{
    _running = false;
    _win->Print("Loop ended!");
}

void Game::Run()
{
    _running = true;
    try
    {
        Texture brickTex = Texture(_win->GetRenderer(), "brick.png");
        if (!brickTex.IsOK())
            _win->Print(brickTex.GetErrorMsg());
        else
        {
            Sprite brick = Sprite(brickTex);
            brick.SetSize(50, 50);
            brick.SetCenter(25, 25);
            brick.SetPosition(_win->GetCenter());
            _win->AddToRenderList(&brick);

            while(_running)
            {
                _time.CalculateTime();
                HandleEvents();

                _win->Render();
            }
        }
    }
    catch(const std::exception& e)
    {
        _win->Print(std::string(e.what()));
    }
}

void Game::HandleEvents()
{
    SDL_Event e;

    while(SDL_PollEvent(&e) != 0)
    {
        switch(e.type)
        {
            case SDL_QUIT:
                End();
            break;

            case SDL_KEYDOWN:
                KeyboardInput(e.key.keysym.sym);
            break;

            default:
                char *str = new char[32];
                sprintf(str, "Unhandled event: %d", e.type);
                _win->Print(std::string(str));
            break;
        }
    }
}

void Game::KeyboardInput(SDL_Keycode key_code)
{
    switch(key_code)
    {
        case SDLK_ESCAPE:
            End();
        break;

        default:
            char *str = new char[32];
            sprintf(str, "Unhandled key: %d", key_code);
            _win->Print(std::string(str));
        break;
    }
    
    SDL_PumpEvents();

    // Tutaj można sprawdzić wciśnięcie klawiszy
}