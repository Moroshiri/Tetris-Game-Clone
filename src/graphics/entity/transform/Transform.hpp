#ifndef _TRANSFORM_HPP_
#define _TRANSFORM_HPP_

#include <SDL2/SDL_image.h>

#include "../../util/Types.hpp"

enum Direction
{
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT,
    DIR_LAST
};

class Transform
{
public:

    Transform();
    ~Transform();

    Rect GetRect();
    void SetRect(Rect rect);

    virtual void Rotate(double angle);
    virtual void SetRotation(double angle);
    double GetRotation();

    virtual void Move(int dx, int dy);
    virtual void Move(Direction dir, int steps);
    virtual void SetPosition(int x, int y);
    virtual void SetPosition(Point pos);

    virtual void Resize(int w, int h);
    virtual void SetSize(int w, int h);
    virtual void SetSize(Size size);

    /*
        Metody GetSize() i GetPosition() nie są potrzebne,
        ponieważ wszystkie te iformacje są zawarte w strukturze Rect
    */
    
protected:
    Rect _rect;
    double _rot;
};

#endif