#include "Sprite.hpp"

Sprite::Sprite(SDL_Renderer* rend) : _texture(rend)
{
    _rend = rend;
}

Sprite::Sprite(Texture tex) : _texture(tex)
{
    _rend = _texture.GetRenderer();
}

Sprite::~Sprite()
{
}

void Sprite::SetTexture(Texture tex)
{
    _texture = tex;
}

Texture Sprite::GetTexture()
{
    return _texture;
}

void Sprite::Render()
{
    //SDL_RenderCopyEx(_rend, _texture.GetSDLTexture(), NULL, &_rect, _rot, &_center, _texture.GetFlip());
    SDL_RenderCopy(_rend, _texture.GetSDLTexture(), NULL, &_rect);
}