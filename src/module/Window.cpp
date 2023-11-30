#include "Window.hpp"

Window::Window()
{
    _screen_width = DEFAULT_SCREEN_WIDTH;
    _screen_height = DEFAULT_SCREEN_HEIGHT;

    _window_title = "SDL";

    _renderListPointer = 0;

    _renderList = new Entity*();
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

    delete _renderList;
}

bool Window::Init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        _errorMsg = ErrorMsg("SDL library initialising error: ") + ErrorMsg(SDL_GetError());
        _errorCode = ERROR_WINDOW_SDLINIT;
        return false;
    }
    
    _window = SDL_CreateWindow(_window_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screen_width, _screen_height, SDL_WINDOW_SHOWN);
    if(_window == NULL)
    {
        _errorMsg = ErrorMsg("Window creation error: ") + ErrorMsg(SDL_GetError());
        _errorCode = ERROR_WINDOW_WINCREATION;
        return false;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if(_renderer == NULL)
    {
        _errorMsg = ErrorMsg("Renderer creation error: ") + ErrorMsg(SDL_GetError());
        _errorCode = ERROR_WINDOW_RENDCREATION;
        return false;
    }
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);

    if(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) < 0)
    {
        _errorMsg = ErrorMsg("SDL_Image library initialising error: ") + ErrorMsg(SDL_GetError());
        _errorCode = ERROR_WINDOW_IMGINIT;
        return false;
    }

    return true;
}

void Window::AddToRenderList(Entity* element)
{
    if (_renderListPointer == 0)
    {
        _renderList[0] = element;
        _renderListPointer++;
    }
    else
    {
        Entity **tmp = _renderList;
        _renderList = new Entity*[_renderListPointer++];
    
        for (uint32_t i = 0; i < _renderListPointer; i++)
            _renderList[i] = tmp[i];
        
        _renderList[_renderListPointer] = element;
        delete tmp;
    }
}

void Window::Render()
{
    SDL_RenderClear(_renderer);

    // Render entities from the list
    if(_renderListPointer != 0)
    for(uint32_t i = 0; i < _renderListPointer; i++)
    {
        _renderList[i]->Render(_renderer);
    }

    SDL_RenderPresent(_renderer);
    //SDL_UpdateWindowSurface(_window);
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

printHandle Window::Print = nullptr;