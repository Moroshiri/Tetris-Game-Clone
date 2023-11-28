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

    SDL_Texture* GetSDLTexture();
    SDL_Renderer* GetRenderer();

    SDL_RendererFlip GetFlip();
    void SetFlip(SDL_RendererFlip flip);

private:
    SDL_Texture* _tex;
    SDL_Surface* _surf;
    SDL_RendererFlip _flip;
    SDL_Renderer* _rend;
};

#endif