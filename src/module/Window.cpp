#include "Window.hpp"

Window::Window()
{
    _screen_width = DEFAULT_SCREEN_WIDTH;
    _screen_height = DEFAULT_SCREEN_HEIGHT;

    _window_title = "SDL";
}

Window::Window(int width, int height, std::string title)
{
    _screen_width = width;
    _screen_height = height;

    _window_title = title;
}

Window::~Window()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
}

bool Window::Init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        sprintf(_errorMsg, "Window initialising error: %s", SDL_GetError());
        return false;
    }
    
    _window = SDL_CreateWindow(_window_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screen_width, _screen_height, SDL_WINDOW_SHOWN);
    if(_window == NULL)
    {
        sprintf(_errorMsg, "Window creation error: %s", SDL_GetError());
        return false;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if(_renderer == NULL)
    {
        sprintf(_errorMsg, "Renderer initialising error: %s", SDL_GetError());
        return false;
    }
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);

    return true;
}



void Window::Render()
{
    //SDL_RenderClear(_renderer);
    //SDL_RenderPresent(_renderer);

    

    SDL_UpdateWindowSurface(_window);
}

