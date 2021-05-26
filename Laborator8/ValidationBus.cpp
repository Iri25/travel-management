#include "ValidationBus.h"
#include <iostream>

ValidationBus::ValidationBus() : ValidationTransport()
{
}

ValidationBus::~ValidationBus()
{
}

int ValidationBus::validate(Transport* transport)
{
	Bus* bus = (Bus*)transport;
	ValidationTransport::validate(bus);
	if (bus->getNumberOfTravelDays() < 0)
	{
		ValidationTransport::errors++;
		ValidationTransport::message += " The number of travel days must be positive! ";
	}
	return ValidationTransport::errors;
}