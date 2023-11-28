#include "Window.hpp"

Window::Window()
{
    _screen_width = DEFAULT_SCREEN_WIDTH;
    _screen_height = DEFAULT_SCREEN_HEIGHT;

    _window_title = "SDL";

    _renderListPointer = 0;
}

Window::Window(int width, int height, std::string title)
{
    _screen_width = width;
    _screen_height = height;

    _window_title = title;

    _renderListPointer = 0;
}

Window::~Window()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);

    delete _renderList;
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

void Window::AddToRenderList(Entity* element)
{
    Entity **tmp = new Entity*[_renderListPointer++];
    
    for (uint32_t i = 0; i < _renderListPointer; i++)
        tmp[i] = _renderList[i];
    
    tmp[_renderListPointer] = element;
    delete _renderList;
    _renderList = tmp;
}

void Window::Render()
{
    //SDL_RenderClear(_renderer);
    //SDL_RenderPresent(_renderer);

    if(_renderListPointer != 0)
    for(uint32_t i = 0; i <= _renderListPointer; i++)
    {
        _renderList[i]->Render();
    }

    SDL_UpdateWindowSurface(_window);
}

SDL_Renderer* Window::GetRenderer()
{
    return _renderer;
}

Point Window::GetCenter()
{
    int w, h;
    SDL_GetWindowSizeInPixels(_window, &w, &h);
    Point res;
    res.x = w/2;
    res.y = h/2;
    return res;
}