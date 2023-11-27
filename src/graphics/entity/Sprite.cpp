#include "Sprite.hpp"

Sprite::Sprite()
{
    _texture = Texture(_rend);
}

Sprite::Sprite(Texture tex)
{
    _texture = tex;
}

Sprite::~Sprite()
{
    delete &_texture;
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
    SDL_RenderCopyEx(_rend, _texture.GetTexture(), NULL, &_rect, _rot, &_texture.GetCenter(), _texture.GetFlip());
}