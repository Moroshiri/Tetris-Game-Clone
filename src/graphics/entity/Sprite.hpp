#ifndef _SPRITE_HPP_
#define _SPRITE_HPP_

#include "transform/Transform.hpp"
#include "../texture/Texture.hpp"
#include "Entity.hpp"

class Sprite : public Transform, public Entity
{
public:

    Sprite();
    Sprite(Texture tex);
    ~Sprite();

    void SetTexture(Texture tex);
    Texture GetTexture();

    virtual void Render();

private:
    Texture _texture;
};

#endif