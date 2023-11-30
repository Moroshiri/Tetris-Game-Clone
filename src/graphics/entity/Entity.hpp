#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

#include <SDL2/SDL.h>

class Entity
{
public:

    Entity();
    ~Entity();

    virtual void Render(SDL_Renderer* rend);

protected:

};

#endif