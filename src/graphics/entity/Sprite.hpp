#ifndef _SPRITE_HPP_
#define _SPRITE_HPP_

#include "transform/Transform.hpp"
#include "../texture/Texture.hpp"
#include "Entity.hpp"

class Sprite : public Transform, public Entity
{
public:

    Sprite(SDL_Renderer* rend);
    Sprite(Texture* tex);
    ~Sprite();

    void SetTexture(Texture* tex);
    Texture* GetTexture();

    virtual void Render(SDL_Renderer* rend);

private:
    Texture* _texture;
};

#endif