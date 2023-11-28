#include "Sprite.hpp"

Sprite::Sprite() : _texture(_rend)
{
    
}

Sprite::Sprite(Texture tex) : _texture(tex)
{

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
    SDL_RenderCopyEx(_rend, _texture.GetSDLTexture(), NULL, &_rect, _rot, &_center, _texture.GetFlip());
}