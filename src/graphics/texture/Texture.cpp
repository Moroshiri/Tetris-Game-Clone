#include "Texture.hpp"

Texture::Texture(SDL_Renderer *rend) : Error()
{
    _rend = rend;
    _tex = nullptr;

    _flip = SDL_FLIP_NONE;
}

Texture::Texture(SDL_Renderer* rend, const char* imgFilePath) : Texture(rend)
{
    _OKFlag = LoadImage(imgFilePath);       
}

Texture::~Texture()
{
    SDL_DestroyTexture(_tex);
    // _rend jest otrzymywane z zewnątrz więc usunięcie go w tym miejscu może powodować błędy
}

bool Texture::LoadImage(const char* path)
{
    SDL_Surface* _surf = IMG_Load(path);
    if(_surf == NULL)
    {
        _errorMsg = ErrorMsg("Image load error: ") + ErrorMsg(SDL_GetError());
        _errorCode = ERROR_TEXTURE_LOAD;
        return false;
    }

    _tex = SDL_CreateTextureFromSurface(_rend, _surf);
    SDL_FreeSurface(_surf);
    if(_tex == NULL)
    {
        _errorMsg = ErrorMsg("Texture create error: ") + ErrorMsg(SDL_GetError());
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