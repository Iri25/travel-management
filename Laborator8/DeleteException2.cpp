#include "DeleteException2.h"

DeleteException2::DeleteException2(string message) : message(message)
{
}

string DeleteException2::getMessage()
{
	return message;
}
