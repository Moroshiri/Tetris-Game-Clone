#ifndef _MODULE_HPP_
#define _MODULE_HPP_

#include <string>

typedef void (*printHandle)(std::string);

class Module
{
public:

    Module();
    ~Module();

    std::string GetError();
    printHandle Print;

protected:
    char* _errorMsg;
};

#endif