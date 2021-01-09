#ifndef JEXCEPTION_H
#define JEXCEPTION_H

#include <stdexcept>
#include <errno.h>
#include <string.h>
#include <stdio.h>
class JException : public std::runtime_error
{
public:
    explicit JException(const std::string& info);

};

#define THROW_ERRNO(fmt,...)   do{                                          \
    char _buf_[256];                                                        \
    int _len = sprintf(_buf_, fmt, __VA_ARGS__);                            \
    if(_len > 0) sprintf(&_buf_[_len], ":%d:%s", errno, strerror(errno));   \
    throw JException(_buf_);                                                \
    }while(0)
#endif // JEXCEPTION_H
