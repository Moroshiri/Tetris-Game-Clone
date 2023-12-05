#ifndef _TRANSFORM_HPP_
#define _TRANSFORM_HPP_

#include <SDL2/SDL_image.h>

#include "../../../util/Types.hpp"

enum Direction
{
    DIR_UP,
    DIR_RIGHT,
    DIR_DOWN,
    DIR_LEFT,
    DIR_LAST
};

class Transform : public Rectangle
{
public:

    Transform();
    ~Transform();

    Rect GetRect();
    //void SetRect(Rect rect);

    virtual void Rotate(double angle);
    virtual void SetRotation(double angle);
    virtual double GetRotation();

    virtual void Move(int dx, int dy);
    virtual void Move(Direction dir, int steps);

    virtual void Resize(int w, int h);

    virtual Point GetCenter();
    virtual void SetCenter(Point point);
    virtual void SetCenter(int x, int y);

    /*
        Metody GetSize() i GetPosition() nie są potrzebne,
        ponieważ wszystkie te iformacje są zawarte w strukturze Rect
    */
    
protected:
    double _rot;
    Point _center;
};

#endif