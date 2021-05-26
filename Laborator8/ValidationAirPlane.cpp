#include "ValidationAirPlane.h"

ValidationAirPlane::ValidationAirPlane() : ValidationTransport()
{
}

ValidationAirPlane::~ValidationAirPlane()
{
}

int ValidationAirPlane::validate(Transport* transport)
{
	AirPlane* airPlane = (AirPlane*)transport;
	ValidationTransport::validate(airPlane);
	if (!(airPlane->getLayover() != 0 || airPlane->getLayover() != 1))
	{
		ValidationTransport::errors++;
		ValidationTransport::message += " The layover must be boolean value! ";
	}
	return ValidationTransport::errors;
}