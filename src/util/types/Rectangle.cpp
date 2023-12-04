#include "Rectangle.hpp"

Rectangle::Rectangle()
{
    _rect.x = 0;
    _rect.y = 0;
    _rect.w = 0;
    _rect.h = 0;
}

Rectangle::Rectangle(Rect rect)
{
    _rect = rect;
}

Rectangle::Rectangle(int x, int y, int w, int h)
{
    _rect.x = x;
    _rect.y = y;
    _rect.w = w;
    _rect.h = h;
}

Rectangle::Rectangle(Point pos, Size size)
{
    _rect.x = pos.x;
    _rect.y = pos.y;
    _rect.w = size.w;
    _rect.h = size.h;
}

Rectangle::Rectangle(int x, int y, Size size)
{
    _rect.x = x;
    _rect.y = y;
    _rect.w = size.w;
    _rect.h = size.h;
}

Rectangle::Rectangle(Point pos, int w, int h)
{
    _rect.x = pos.x;
    _rect.y = pos.y;
    _rect.w = w;
    _rect.h = h;
}

Rectangle::~Rectangle()
{
    
}

Rect Rectangle::GetRect()
{
    return _rect;
}

void Rectangle::SetRect(Rect rect)
{
    _rect = rect;
}

Point Rectangle::GetPosition()
{
    Point res;
    res.x = _rect.x;
    res.y = _rect.y;
    return res;
}

void Rectangle::SetPosition(Point pos)
{
    _rect.x = pos.x;
    _rect.y = pos.y;
}

void Rectangle::SetPosition(int x, int y)
{
    _rect.x = x;
    _rect.y = y;
}

Size Rectangle::GetSize()
{
    Size res;
    res.w = _rect.w;
    res.h = _rect.h;
    return res;
}

void Rectangle::SetSize(Size size)
{
    _rect.w = size.w;
    _rect.h = size.h;
}

void Rectangle::SetSize(int w, int h)
{
    _rect.w = w;
    _rect.h = h;
}

bool Rectangle::operator==(Rectangle a)
{
    return _rect.x == a.GetRect().x && _rect.y == a.GetRect().y && _rect.w == a.GetRect().w && _rect.h == a.GetRect().h; 
}

bool Rectangle::operator!=(Rectangle a)
{
    return _rect.x != a.GetRect().x && _rect.y != a.GetRect().y && _rect.w != a.GetRect().w && _rect.h != a.GetRect().h; 
}

void Rectangle::operator=(Rect a)
{
    _rect = a;
}

void Rectangle::operator=(Point a)
{
    SetPosition(a);
}

void Rectangle::operator=(Size a)
{
    SetSize(a);
}