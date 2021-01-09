#include "jexception.h"

JException::JException(const std::string& info):runtime_error(info)
{

}
