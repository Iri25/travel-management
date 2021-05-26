#include "AirPlane.h"
#include <string>

AirPlane::AirPlane() : Transport()
{
	this->layover = 0;
}

AirPlane::AirPlane(string code, string arrivalLocation, string deppartureLocation, string date, int totalNumberOfSeats, int numberOfReservedSeats, bool layover) : Transport(code, arrivalLocation, deppartureLocation, date, totalNumberOfSeats, numberOfReservedSeats)
{
	this->layover = layover;
}

AirPlane::AirPlane(const AirPlane& airPlane) : Transport(airPlane)
{
	this->layover = airPlane.layover;
}

AirPlane::~AirPlane()
{
}

Transport* AirPlane::clone()
{
	return new AirPlane(this->code, this->arrivalLocation, this->deppartureLocation, this->date, this->totalNumberOfSeats, this->numberOfReservedSeats, this->layover);
}

AirPlane& AirPlane::operator=(const AirPlane& airPlane)
{
	Transport::operator=(airPlane);
	this->layover = airPlane.layover;
	return *this;
}

bool AirPlane::operator==(const AirPlane& airPlane)
{
	return Transport::operator==(airPlane);
}

bool AirPlane::getLayover()
{
	return this->layover;
}

void AirPlane::setLayover(bool layover)
{
	this->layover = layover;
}

string AirPlane::toString(string delimiter)
{
	return "Avion" + delimiter + Transport::toString(delimiter) + delimiter + to_string(this->layover);
}