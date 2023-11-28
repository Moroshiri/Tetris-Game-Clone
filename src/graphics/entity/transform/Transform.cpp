#include "Transform.hpp"

Transform::Transform()
{
    _rect.h = 10;
    _rect.w = 10;
    _rect.x = 0;
    _rect.y = 0;

    _rot = 0.0;
}

Transform::~Transform()
{
}

Rect Transform::GetRect()
{
    return _rect;
}

void Transform::Move(int dx, int dy)
{
    _rect.x += dx;
    _rect.y += dy;
}

void Transform::Move(Direction dir, int steps)
{
    int dx, dy;

    dy += dir==DIR_UP?steps:(dir==DIR_DOWN?-steps:0);
    dx += dir==DIR_RIGHT?steps:(dir==DIR_LEFT?-steps:0);

    _rect.x += dx;
    _rect.y += dy;
}

void Transform::SetPosition(int x, int y)
{
    _rect.x = x;
    _rect.y = y;
}

void Transform::SetPosition(Point pos)
{
    _rect.x = pos.x;
    _rect.y = pos.y;
}

void Transform::Resize(int w, int h)
{
    _rect.w += w;
    _rect.h += h;
}

void Transform::SetSize(int w, int h)
{
    _rect.w = w;
    _rect.h = h;
}

void Transform::SetSize(Size size)
{
    _rect.w = size.w;
    _rect.h = size.h;
}

double Transform::GetRotation()
{
    return _rot;
}

void Transform::Rotate(double angle)
{
    _rot += angle;

    if (_rot >= 360)
        _rot -= 360;
    if (_rot <= -360)
        _rot += 360;
}

void Transform::SetRotation(double angle)
{
    _rot = angle;

    if (_rot >= 360)
        _rot -= 360;
    if (_rot <= -360)
        _rot += 360;
}

Point Transform::GetCenter()
{
    return _center;
}

void Transform::SetCenter(Point point)
{
    _center = point;
}

void Transform::SetCenter(int x, int y)
{
    _center.x = x;
    _center.y = y;
}