#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "../graphics/entity/Sprite.hpp"
#include "../util/Error.hpp"

const int DEFAULT_SCREEN_WIDTH = 800;
const int DEFAULT_SCREEN_HEIGHT = 600;

typedef void (*printHandle)(std::string);

class Window : public Error
{
public:

    Window();
    Window(int width, int height, std::string title);
    
    ~Window();

    // Inicjalizuje okno programu i renderer
    bool Init();

    //void Render(SDL_Texture* tex, SDL_Rect* rect);
    void Render();
    void AddToRenderList(Entity* element);

    SDL_Renderer* GetRenderer();
    Point GetCenter();

    static printHandle Print;

private:
    int _screen_width, _screen_height;
    std::string _window_title;

    Entity **_renderList;
    uint32_t _renderListPointer;

    SDL_Window *_window;

    SDL_Renderer *_renderer;
};

#endif