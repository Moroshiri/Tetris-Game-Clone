#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

#include <SDL.h>

class Entity
{
public:

    Entity();
    ~Entity();

    virtual void Render(SDL_Renderer* renderer);

};

#endif