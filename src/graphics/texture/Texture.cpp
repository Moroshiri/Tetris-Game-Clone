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
        throw new std::exception();
}

Texture::~Texture()
{
    delete _tex;
    delete &_center;
    delete &_flip;
    // _surf jest usuwane od razu po utworzeniu _tex
    // _rend jest otrzymywane z zewnątrz więc usunięcie go w tym miejscu może powodować błędy
}

bool Texture::LoadImage(const char* path)
{
    _surf = IMG_Load("../assets/img/smile.png");
    if(_surf == NULL)
    {
        sprintf(_errorMsg, "Load image error: %s", SDL_GetError());
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