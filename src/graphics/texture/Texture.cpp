#include "Texture.hpp"

Texture::Texture(SDL_Renderer *rend)
{
    _rend = rend;
    _tex = nullptr;
    _surf = nullptr;

    _flip = SDL_FLIP_NONE;
}

Texture::Texture(SDL_Renderer* rend, const char* imgFilePath) : Texture(rend)
{
    if (!LoadImage(imgFilePath))
    {
        _OKFlag = false;
    }
        
}

Texture::~Texture()
{
    SDL_DestroyTexture(_tex);
    // _surf jest usuwane od razu po utworzeniu _tex
    // _rend jest otrzymywane z zewnątrz więc usunięcie go w tym miejscu może powodować błędy
}

bool Texture::LoadImage(const char* path)
{
    _surf = IMG_Load(path);
    if(_surf == NULL)
    {
        sprintf(_errorMsg, "Image load error: %s", SDL_GetError());
        _errorCode = ERROR_TEXTURE_LOAD;
        return false;
    }

    _tex = SDL_CreateTextureFromSurface(_rend, _surf);
    SDL_FreeSurface(_surf);
    if(_tex == NULL)
    {
        sprintf(_errorMsg, "Texture create error: %s", SDL_GetError());
        _errorCode = ERROR_TEXTURE_CREATE;
        return false;
    }

    return true;
}

SDL_Texture* Texture::GetSDLTexture()
{
    return _tex;
}

SDL_Renderer* Texture::GetRenderer()
{
    return _rend;
}

SDL_RendererFlip Texture::GetFlip()
{
    return _flip;
}

void Texture::SetFlip(SDL_RendererFlip flip)
{
    _flip = flip;
}