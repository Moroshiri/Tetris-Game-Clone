#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "Module.hpp"
#include "../graphics/entity/Sprite.hpp"

const int DEFAULT_SCREEN_WIDTH = 800;
const int DEFAULT_SCREEN_HEIGHT = 600;

class Window : public Module
{
public:

    Window();
    Window(int width, int height, std::string title);
    
    ~Window();

    // Inicjalizuje okno programu i renderer
    bool Init();

    void Render();
    void AddToRenderList(Entity* element);

private:
    int _screen_width, _screen_height;
    std::string _window_title;

    SDL_Window *_window;

    SDL_Renderer *_renderer;

    
};

#endif