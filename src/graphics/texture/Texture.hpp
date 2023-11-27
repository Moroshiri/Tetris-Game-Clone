#ifndef _TEXTURE_HPP_
#define _TEXTURE_HPP_

#include <SDL2/SDL_image.h>
#include "../../util/Types.hpp"
#include "../../util/Error.hpp"

class Texture : public Error
{
public:

    Texture(SDL_Renderer* rend);
    Texture(SDL_Renderer* rend, const char* imgFilePath);
    ~Texture();

    bool LoadImage(const char* path);

    SDL_Texture* GetTexture();
    Point GetCenter();
    SDL_RendererFlip GetFlip();

private:
    SDL_Texture* _tex;
    SDL_Surface* _surf;
    Point _center;
    SDL_RendererFlip _flip;
    SDL_Renderer* _rend;
};

#endif