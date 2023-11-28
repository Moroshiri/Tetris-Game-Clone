#include "Error.hpp"

Error::Error()
{ 
    _errorMsg = new char[0];
    _errorCode = ERROR_BLANK;
    _OKFlag = true;
}

Error::~Error()
{
    delete _errorMsg;
}

std::string Error::GetErrorMsg()
{
    return std::string(_errorMsg);
}

ErrorCode Error::GetErrorCode()
{
    return _errorCode;
}

bool Error::IsOK()
{
    return _OKFlag;
}


ResourceLoadException::ResourceLoadException() : _mes("Resource load error!")
{
    ;
}

ResourceLoadException::ResourceLoadException(const char* mes) : _mes(mes)
{
    ;
}

const char* ResourceLoadException::what()
{
    return _mes;
}