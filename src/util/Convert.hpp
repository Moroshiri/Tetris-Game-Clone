#ifndef _CONVERT_HPP_
#define _CONVERT_HPP_

#include <string>

inline std::string toString(int n)
{
    char* str = new char[7];
    sprintf(str, "%d", n);
    return std::string(str);
}

#endif