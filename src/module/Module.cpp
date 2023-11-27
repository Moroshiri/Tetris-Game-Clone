#include "Module.hpp"

Module::Module()
{
    Print = nullptr;
}

Module::~Module()
{ }

std::string Module::GetError()
{
    return std::string(_errorMsg);
}