#include "ValidationException.h"
#include <string.h>

ValidationException::ValidationException()
{
}

ValidationException::~ValidationException()
{
}

ValidationException::ValidationException(string message)
{
	this->message = message;
}

string ValidationException::what() throw()
{
	return message;
}