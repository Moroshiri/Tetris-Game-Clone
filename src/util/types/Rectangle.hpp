#ifndef _RECTANGLE_HPP_
#define _RECTANGLE_HPP_

#include "DefTypes.hpp"

class Rectangle
{
public:
    Rectangle();
    Rectangle(Rect rect);
    Rectangle(int x, int y, int w, int h);
    Rectangle(Point pos, Size size);
    Rectangle(int x, int y, Size size);
    Rectangle(Point pos, int w, int h);
    ~Rectangle();

    virtual Rect GetRect();
    virtual void SetRect(Rect rect);

    virtual Point GetPosition();
    virtual void SetPosition(Point pos);
    virtual void SetPosition(int x, int y);

    virtual Size GetSize();
    virtual void SetSize(Size size);
    virtual void SetSize(int w, int h);

    virtual bool operator==(Rectangle a);
    virtual bool operator!=(Rectangle a);
    virtual void operator=(Rect a);
    virtual void operator=(Point a);
    virtual void operator=(Size a);

protected:
    Rect _rect;
};

#endif