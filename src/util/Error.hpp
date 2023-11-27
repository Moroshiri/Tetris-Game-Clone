#ifndef _ERROR_HPP_
#define _ERROR_HPP_

#include <string>

enum ErrorCode
{
    ERROR_BLANK,
    ERROR_WINDOW_INIT,
    ERROR_TEXTURE_LOAD,
    ERROR_TEXTURE_CREATE,
    ERROR_LAST
};

class Error
{
public:

    Error();
    Error(ErrorCode code);
    ~Error();

    std::string GetErrorMsg();
    ErrorCode GetErrorCode();

protected:
    char* _errorMsg;
    ErrorCode _errorCode;
};

#endif