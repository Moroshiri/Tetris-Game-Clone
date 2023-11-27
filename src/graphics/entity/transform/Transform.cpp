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
    delete &_rect;
    delete &_rot;
}

double Transform::GetRotation()
{
    return _rot;
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

void Transform::SetPosition(int x, int y)
{
    _rect.x = x;
    _rect.y = y;
}

void Transform::Resize(int w, int h)
{
    _rect.w = w;
    _rect.h = h;
}