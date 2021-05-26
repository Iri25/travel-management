#include "ValidationTransport.h"

ValidationTransport::ValidationTransport()
{
	this->errors = 0;
}

ValidationTransport::~ValidationTransport()
{
}

int ValidationTransport::validate(Transport* transport)
{
	if (transport->getCode().empty())
	{
		errors++;
		message += " The code cannot be empty! ";
	}
	if (transport->getArrivalLocation().empty())
	{
		errors++;
		message += " The arrival location cannot be empty! ";
	}
	if (transport->getDeppartureLocation().empty())
	{
		errors++;
		message += " The depparture cannot be empty! ";
	}
	if (transport->getDate().empty())
	{
		errors++;
		message += " The date cannot be empty! ";
	}
	if (transport->getTotalNumberOfSeats() <= 0)
	{
		errors++;
		message += " The total number of seats must be positive! ";
	}
	if (transport->getNumberOfReservedSeats() < 0)
	{
		errors++;
		message += " The number of reserved seats must be positive! ";
	}
	if (transport->getNumberOfReservedSeats() > transport->getTotalNumberOfSeats())
	{
		errors++;
		message += " The number of reserved seats cannot be greather than the total number of seats! ";
	}
	return errors;
}

string ValidationTransport::toString()
{
	return message;
}