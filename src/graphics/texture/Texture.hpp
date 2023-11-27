#ifndef _TEXTURE_HPP_
#define _TEXTURE_HPP_

#include <SDL2/SDL_image.h>
#include "../util/Types.hpp"

class Texture
{
public:

    Texture();
    ~Texture();

    bool LoadFromFile(const char* path);

    SDL_Texture* GetTexture();
    Point GetCenter();
    SDL_RendererFlip GetFlip();

private:
    SDL_Texture* _tex;
    SDL_Surface* _surf;
    Point _center;
    SDL_RendererFlip _flip;

};

#endif