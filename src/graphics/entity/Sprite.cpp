#include "Sprite.hpp"

Sprite::Sprite(SDL_Renderer* rend) : _texture(new Texture(rend))
{ }

Sprite::Sprite(Texture* tex) : _texture(tex)
{ }

Sprite::~Sprite()
{
}

void Sprite::SetTexture(Texture* tex)
{
    _texture = tex;
}

Texture* Sprite::GetTexture()
{
    return _texture;
}

void Sprite::Render(SDL_Renderer* rend)
{
    SDL_RenderCopyEx(rend, _texture->GetSDLTexture(), NULL, &_rect, _rot, &_center, _texture->GetFlip());
    //SDL_RenderCopy(rend, _texture->GetSDLTexture(), NULL, &_rect);
}