#include "Error.hpp"

Error::Error()
{ 
    _errorMsg = "";
    _errorCode = ERROR_BLANK;
}

Error::Error(ErrorCode code)
{
    _errorMsg = "";
    _errorCode = code;
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