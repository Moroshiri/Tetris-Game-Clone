#ifndef _CONVERT_HPP_
#define _CONVERT_HPP_

#include <string>

#include "Types.hpp"

inline std::string toString(int n)
{
    char* str = new char[7];
    sprintf(str, "%d", n);
    return std::string(str);
}

inline Size newSize(int w, int h)
{
    Size res;
    res.w = w;
    res.h = h;
    return res;
}

inline Point newPoint(int x, int y)
{
    Point res;
    res.x = x;
    res.y = y;
    return res;
}

inline Rect newRect(int x, int y, int w, int h)
{
    Rect res;
    res.x = x;
    res.y = y;
    res.w = w;
    res.h = h;
    return res;
}
#endif