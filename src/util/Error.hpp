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
    ~Error();

    std::string GetErrorMsg();
    ErrorCode GetErrorCode();

    bool IsOK();

protected:
    char* _errorMsg;
    ErrorCode _errorCode;
    bool _OKFlag;
};

class ResourceLoadException : public std::exception
{
public:
    ResourceLoadException();
    ResourceLoadException(const char* message);

    const char *what();
private:
    const char* _mes;
};

#endif