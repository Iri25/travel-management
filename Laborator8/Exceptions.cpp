#include "Exception.h"

Exception::Exception(string message) : message(message)
{
}

string Exception::getMessage()
{
	return message;
}