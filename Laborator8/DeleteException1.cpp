#include "DeleteException1.h"

DeleteException1::DeleteException1(string message) : DeleteException2(message)
{
}

string DeleteException1::getMessage()
{
	return message;
}
